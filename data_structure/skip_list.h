#include "arena.h"
// 模版编程,好久不用了,
template <typename Key, class Comparator>
class SkipList
{
private:
    // TODO 这边没有定义啊,怎么用?
    struct Node;
    /* 我觉得更像是一种宏,但是只在某个范围内部使用,然后可以作为状态机的某种状态存在 */
    enum
    {
        kMaxHeight = 12
    };

public:
    // 开始定义各种构造函数
    // 1 禁止隐式转换,也就是 禁止下面的用法
    /*
    SkipList sl=1;
     */
    explicit SkipList(Comparator cmp, Arena *arena);
    // 以后就不允许 用另外一个跳表初始化自己,也不允许等号初始化自己
    SkipList(const SkipList &) = delete;
    SkipList &operator=(const SkipList &) = delete;

    // 功能函数
    Node *NewNode(const Key &key, int height);

    Comparator const compare_;
    /* 这个指针永远指向这个对象 */
    Arena *const arena_; // Arena used for allocations of nodes
    Node *const head_;
    /* 跳表也有高度, */
    std::atomic<int> max_height_;
};

template <typename Key, class Comparator>
SkipList<Key, Comparator>::SkipList(Comparator cmp, Arena *arena)
    : compare_(cmp),
      arena_(arena),
      head_(NewNode(0 /* any key will do */, kMaxHeight)),
      max_height_(1)
{
    for (int i = 0; i < kMaxHeight; i++)
    {
        head_->SetNext(i, nullptr);
    }
}
// 因为在函数里面定义的node ,所以函数需要定义作用域typename SkipList<Key, Comparator>::Node
template <typename Key, class Comparator>
typename SkipList<Key, Comparator>::Node *SkipList<Key, Comparator>::NewNode(const Key &key, int height)
{
    // *const 符号和指针地址是绑定的,
    char *const node_memory = arena_->AllocateAligned(
        sizeof(Node) + sizeof(std::atomic<Node *>) * (height - 1));
    return new (node_memory) Node(key);
    return nullptr;
}
