#include <iostream>
using namespace std;

struct Vector
{
    int* m_pVect, // Pointer to the buffer
        m_nCount, // Control how many elements are actually used
        m_nMax, // Control how many are allocated as maximum
        m_nDelta; // To control the growing
};

void Resize(Vector* pThis)
{
    int* pTemp, i;
    pTemp = new int[pThis->m_nMax + pThis->m_nDelta];
    for (i = 0; i < pThis->m_nMax; i++)
        pTemp[i] = pThis->m_pVect[i];
    delete[]pThis->m_pVect;
    pThis->m_pVect = pTemp;
    pThis->m_nMax += pThis->m_nDelta;
}

void Insert(Vector* pThis, int elem)
{
    if (pThis->m_nCount == pThis->m_nMax) // Verify the overflow
        Resize(pThis); // Resize the vector before inserting elem
    // Insert the element at the end of the sequence
    pThis->m_pVect[pThis->m_nCount++] = elem;
}

int main()
{
    Vector vec;
    vec.m_pVect = NULL;
    vec.m_nCount = 0;
    vec.m_nMax = 0;
    vec.m_nDelta = 10;

    Insert(&vec, 5);
    Insert(&vec, 9);
    Insert(&vec, 10);

    for (int i = 0; i < vec.m_nCount; i++)
        cout << vec.m_pVect[i] << " ";

    delete[] vec.m_pVect;

    return 0;
}
