#include<dict.h>
#include<node.h>
#include<stdio.h>

int main(int argc, char const *argv[]){
    dict * D = Dict(10);

    int array[] = {20, 123, 13, 53, 16};

    D = insert_into_dict(D, "key1", array);

    int * array2 = (int *)lookup_dict(D, "key1");

    int iter_ = 0;
    for(iter_ = 0; iter_ < 5; iter_++) printf("%d\n", array2[iter_]);
}
