#include <iostream>
using namespace std;

template<typename T>
class CVector
{
public:
    int delta = 10;
    T* m_pVect, // Pointer to the buffer
        m_nCount, // Control how many elements are actually used
        m_nMax, // Control how many are allocated as maximum
        m_nDelta; // To control the growing
    void Resize() // Resize the vector when occurs an overflow
    {
        T* newvector = new T[delta * 2];
        for (int i = 0; i < delta; i++) newvector[i] = m_pVect[i];
        delete[] m_pVect;
        m_pVect = newvector;
        m_nMax += m_nDelta;

    }
    CVector() // Constructor
    {
        m_pVect = (T*)malloc(delta * sizeof(T));
    }
    void Insert(T elem); // Insert a new element
    // More methods go here
};


template<typename T>
void CVector<T>::Insert(T elem)
{
    if (m_nCount == m_nMax) // Verify the overflow
        Resize(); // Resize the vector before inserting elem
    m_pVect[m_nCount++] = elem; // Insert the element at the end
}


int main()
{
    CVector<int> vec1;
    for (int i = 0; i < 10; i++) vec1.Insert(1);
    for (int i = 0; i < 10; i++) cout << vec1.m_pVect[i] << " ";

}
