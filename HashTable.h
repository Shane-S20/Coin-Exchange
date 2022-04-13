#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <iostream>

template <class K,class D>
struct DataPair
{
    K key;
    D data;
};

template <class K>
unsigned int hashFunc(K key,unsigned int size)
{
   return key%size;
}
template <class K,class D>
class HashTable
{
public:
    typedef std::vector<DataPair<K,D> > BucketType;
    HashTable(unsigned int size) {m_table.resize(size*2);}
    unsigned int size() {return m_table.size();}
    D &operator[](K key)
    {
        unsigned int index=hashFunc(key,size());
        //Get the bucket at index
        BucketType &bucket=m_table[index];
        //traverse bucket and search for key
        for(int i=0;i<bucket.size();i++)
            //if key exists
            if(key==bucket[i].key)
                return bucket[i].data; //return data at key
        DataPair<K,D> DP={key,D()};
        bucket.push_back(DP);
        return bucket[bucket.size()-1].data;
    }
    void display()
    {
        for(int i=0;i<size();i++)
        {
            for(int k=0;k<m_table[i].size();k++)
            {
                std::cout<<m_table[i][k].key<<" - "<<m_table[i][k].data<<std::endl;
            }
        }
    }
private:
    std::vector<BucketType> m_table;
};

#endif //HASHTABLE_H
