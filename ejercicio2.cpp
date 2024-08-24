#include <iostream>
using namespace std;

class CVector
{
public:
    int* m_pVect, // Pointer to the buffer
        m_nCount, // Control how many elements are actually used
        m_nMax, // Control how many are allocated as maximum
        m_nDelta; // To control the growing
    void Resize() // Resize the vector when occurs an overflow
    {
        int* newvector = new int[delta * 2];
        for (int i = 0; i < delta; i++) newvector[i] = m_pVect[i];
        delete[] m_pVect;
        m_pVect = newvector;
        m_nMax += m_nDelta;
        
    }
    int delta = 10;
    CVector() // Constructor
    {
        m_pVect = (int *)malloc(delta * sizeof(int));
    }
    void Insert(int elem); // Insert a new element
    // More methods go here
};


void CVector::Insert(int elem)
{
    if (m_nCount == m_nMax) // Verify the overflow
        Resize(); // Resize the vector before inserting elem
    m_pVect[m_nCount++] = elem; // Insert the element at the end
}


int main()
{
    CVector vec1;
    for(int i=0;i<10;i++) vec1.Insert(1);
    for (int i = 0; i < 10; i++) cout << vec1.m_pVect[i]<<" ";

}
