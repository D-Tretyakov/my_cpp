#include <unordered_map>
#include <list>

template<typename T>
struct LRUCache
{
    LRUCache();
    bool update();

    private:
        using ListIt = typename std::list<T>::iterator;

        std::unordered_map<T, ListIt> m_hash;
        std::list<T> m_list;
};