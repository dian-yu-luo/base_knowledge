#include "arena.h"
// 模版编程,好久不用了,
template <typename Key, class Comparator>
class SkipList
{
private:
    // TODO 这边没有定义啊,怎么用?
    struct Node;

public:
    // 开始定义各种构造函数
    explicit SkipList(Comparator cmp, Arena *arena);
};

template <typename Key, class Comparator>
inline SkipList<Key, Comparator>::SkipList(Comparator cmp, Arena *arena)
{
}
