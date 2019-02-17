#include <assert.h>
#include <map>
#include <limits>
#include <iostream>
#include <typeinfo>

template<class K, class V>
class interval_map {
    friend void IntervalMapTest();

private:
    std::map<K,V> m_map;

public:
    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map( V const& val) {
        m_map.insert(m_map.begin(),std::make_pair(std::numeric_limits<K>::lowest(),val));
    }

    // Assign value val to interval a. 
    // Overwrite previous values in this interval. 
    // Do not change values outside this interval.
    // Conforming to the C++ Standard Library conventions, the interval 
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval, 
    // and assign must do nothing.
    void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
        if (keyBegin < keyEnd)  { // if equals do nothing
            auto it_begin = --m_map.upper_bound(keyBegin);
            auto it_end   = --m_map.upper_bound(keyEnd);

            // V prev_value = it_begin->second;
            V next_value = it_end->second;

            bool is_splice = !(it_begin->second == next_value);
            if (is_splice) m_map.erase(++it_begin, ++it_end);

            m_map.insert(std::make_pair(keyBegin, val));
            m_map.insert(std::make_pair(keyEnd, next_value));
        }
    }

    // look-up of the value associated with key
    V const& operator[]( K const& key ) const {
        return ( --m_map.upper_bound(key) )->second;
    }
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a function IntervalMapTest() here that tests the
// functionality of the interval_map, for example using a map of unsigned int
// intervals to char.

/* bug size_t A C G .. -> B C G .. */
/* bug int .. B C G .. -> .. B A G .. */

void IntervalMapTest ()
{
    typedef int Key;
    Key I = std::numeric_limits<Key>::max();
    interval_map<Key,char> data('A');

    auto test = [&data] (Key from, Key to, char value) {
        std::cout << std::endl;
        std::cout << value << " is assigned from " << from << " to " << to << std::endl;
        data.assign(from, to, value);
        for (Key key = 0; key < 10; key++)
            std::cout << key << " => " << data[key] << std::endl;
        for (auto it = data.m_map.begin(); it != data.m_map.end(); it++)
            std::cout << '{' << it->first << ',' << it->second << "} ";
        std::cout << std::endl;
    };
    
    test(3, 6, 'B');
    test(1, 4, 'C');
    test(0, 1, 'D');
    test(7, 8, 'E');
    test(7, 3, 'F');
    test(7, 7, 'G');
    test(8, I, 'H');
    test(2, 9, 'I');
    test(1, 2, 'J'); // fails
}

int main() {
    std::map<int,char> data;
    data.insert(std::make_pair(0, '0'));
    data.insert(std::make_pair(1, '1'));
    data.insert(std::make_pair(2, '2'));
    data.erase(1);
    data.insert(std::make_pair(1, '5'));
    for (auto it = data.begin(); it != data.end(); it++)
        std::cout << '{' << it->first << ',' << it->second << "} ";
    std::cout << std::endl;
    // IntervalMapTest();
}
