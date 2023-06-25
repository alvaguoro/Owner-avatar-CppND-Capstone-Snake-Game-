#ifndef CONCURRENTQUEUE_H
#define CONCURRENTQUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T> class ConcurrentQueue {
 public:
    void push(T element)
    {
        std::lock_guard<std::mutex> _lock_guard(_mtx);
        _queue.push(element);
        _cond.notify_one();
    }

    T pop()
    {
        std::lock_guard<std::mutex> _lock_guard(_mtx);
        
        T front = _queue.front();
        _queue.pop();

        return front;
    }

    void wait(bool &shouldNotExit)
    {
        std::unique_lock<std::mutex> _unique_lock(_wait_mtx);
        _cond.wait(_unique_lock, [this, &shouldNotExit] { return !empty() || !shouldNotExit; });
    }

    bool empty()
    {
        std::lock_guard<std::mutex> _lock_guard(_mtx);
        return _queue.empty();
    }

    void release()
    {
        _cond.notify_one();
    }

 private:
    std::mutex _mtx;
    std::mutex _wait_mtx;
    std::condition_variable _cond;
    std::queue<T> _queue;
};

#endif