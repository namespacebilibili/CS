#include <iostream>
namespace heap
{
#define maxheap //大根堆
#ifdef maxheap
#define op >
#else
#define op <
#endif
    const int MAXN = 1000005;
    int heap[MAXN], size;
    void swim(int n)
    {
        for (int i = n; i > 1 && heap[i] op heap[i / 2]; i /= 2)
            std::swap(heap[i], heap[i / 2]);
    }
    int son(int n)
    {
        return n * 2 + (n * 2 + 1 <= size && heap[n * 2 + 1] op heap[n * 2]);
    }
    void sink(int n)
    {
        for (int i = n, t = son(i); t <= size && heap[t] op heap[i]; i = t, t = son(i))
            std::swap(heap[i], heap[t]);
    }
    void push(int x)
    {
        heap[++size] = x;
        swim(size);
    }
    void pop()
    {
        std::swap(heap[1], heap[--size]);
        sink(1);
    }
    int top()
    {
        return heap[1];
    }
    void build(int A[], int n)
    {
        std::memcpy(heap + 1, A, sizeof(int) * n);
        size = n;
        for (int i = n / 2; i >= 0; i--)
            sink(i);
    }
}