# C-Dict
A tiny library that brings the support of dictionaries to C programming language with a fast lookup using hash tables. dict type can be used to associate large arrays with string keys. 


### How it works ?
The library has a pretty simple implementation, when we create a `dict()` it first initializes the lookup table of finite length < 4096.
The lookup table is just a list of pointers to `node_entry struct`. `node_entry` is a linked list node that contains the key value fields.
`murmur_32` hash is used to map string keys to a unqiue `long int` and then the `long int` is reduced to a unqiue lookup table index using a simple
modulo operation, i.e `unqiue_index = long_hash % LOOKUP_TABLE_SIZE`. In case of collision, a new linked list node is added to existing list pointed by some pointer
from lookup table.

### Choosing lookup table size :
It is clear that long hashes are mapped to lookup table usign modulo reduction. A lookup table size should be choosen in such a way that number of collisions are less.
For example, if Lookup table is of length 1, every insertion is a collision, so probability is 1.0, similarly if we choose a lookup size of 3, the probability of
collision will be reduced to 1/3. In general, if `N` is the size of lookup table, the probability of collision is `1/N`. Choosing large values of `N` can result in less collision,
so most entries can be fetched in O(1) time. However, creating large lookup tables can occupy more memory. A lookup table of 
length 1000 can occupy 1000 * 32 (length of pointer on 32-bit machine) bits. We are planning to reduce the length of lookup table by figuring out new ways,
as of now, the size of lookup table is limited to 4096 entries. So size of lookup table will be `0 < size < 4096` .

### Usage example : 

```C
#include<dict.h>
#include<stdio.h>

//include dict.h to access dict type


int main(int argc, char const *argv[]){
    //create a dict pointer of lookup table length = 10
    //lookup table length does not impose any restriction on
    //number of elements you insert to dict
    //lookup length defines the mapping range. 
    //All hashes are now reduced to values between 0 - 9
    //Collisions are handled by adding a node to linked list.
    //This techinque is also called as bucketing
    dict * D = Dict(10);

    int array[] = {20, 123, 13, 53, 16};
    int array2[] = {30, 41, 12, 33, 12};

    //insert a key value pair
    D = insert_into_dict(D, "key1", array);
    D = insert_into_dict(D, "key2", array2);
    
    //get the value through key
    int * value = (int *)lookup_dict(D, "key1");

}

```
