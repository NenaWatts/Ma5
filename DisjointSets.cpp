#include "DisjointSets.h"

/**
 * Construct the disjoint sets object.
 * numElements is the initial number of disjoint sets.
 */
DisjointSets::DisjointSets(int numElements) : s(numElements, -1)
{
}

/**
 * Union two disjoint sets.
 */
void DisjointSets::unionSets(int root1, int root2)
{
    root1= find(root1);
    root2= find(root2);

    if(root1==root2)
    {
        return;
    }

    if(s[root1] < s[root2])
    {
        s[root1] += s[root2];
        s[root2]= root1;
    }
    else
    {
        s[root2]+= s[root1];
        s[root1] = root2;

    }
    //s[root2] = root1;
    // TODO
}


/**
 * Perform a find (does not change anything).
 * Return the set containing x.
 */
int DisjointSets::find(int x) const
{
    if (s[x] < 0)
    {
        return x;
    }
    else
    {
        return find(s[x]);
    }
    //return s[0];
}


/**
 * Perform a find with path compression (the mutator version).
 * Return the set containing x.
 */
int DisjointSets::find(int x)
{
    // TODO
    if (s[x] < 0)
    {
        return x;
    }
    else
    {
        return s[x] = find(s[x]);
    }

    
}
