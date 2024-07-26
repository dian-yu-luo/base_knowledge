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
    // 1 禁止隐式转换,也就是 禁止下面的用法
    /*
    SkipList sl=1;
     */
    explicit SkipList(Comparator cmp, Arena *arena);
    Comparator const compare_;
    /* 这个指针永远指向这个对象 */
    Arena *const arena_; // Arena used for allocations of nodes
    Node *const head_;
};

template <typename Key, class Comparator>
SkipList<Key, Comparator>::SkipList(Comparator cmp, Arena *arena)
    : compare_(cmp),
      arena_(arena)
{
}
