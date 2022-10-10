#include <iostream>
#include <unordered_map>
#include <list>

// Class declaration
template<typename T>
struct LRUCache
{
    LRUCache(size_t a_size);
    
    void update(const T& a_entry);
    const std::list<T>& get_state() const;
    void debug_print() const;

    private:
        using ListIt = typename std::list<T>::iterator;

        std::unordered_map<T, ListIt> m_hash;
        std::list<T> m_list;

        size_t m_size;
        size_t m_cache_hits;
};


//Methods definitions
template<typename T>
LRUCache<T>::LRUCache(size_t a_size)
: m_size(a_size)
{
    if (m_size == 0) 
        throw std::runtime_error("Cannot construct cache with size 0");
}


template<typename T>
void LRUCache<T>::update(const T& entry)
{
    auto found = m_hash.find(entry);
    if (found != m_hash.end()) 
    {
        // iterator to found entry list element
        auto it = found->second;
        // move entry to front if it was found 
        if (found->second != m_list.begin())
            m_list.splice(m_list.begin(), m_list, it, std::move(it));
        
        m_cache_hits += 1;
    }

    if (m_list.size() == m_size)
    {
        m_hash.erase(m_list.back());
        m_list.pop_back();
    }

    m_list.push_front(entry);
    m_hash[entry] = m_list.begin();
}

template<typename T>
const std::list<T>& LRUCache<T>::get_state() const
{
    return m_list;
}

template<typename T>
void LRUCache<T>::debug_print() const
{
    std::cout << "Current cached values:\n\t{ ";
    for (const auto& element : m_list)
        std::cout << element << " ";
    std::cout << "}" << std::endl;
}
