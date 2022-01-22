#include <iostream>
#include <vector>
#include <array>
#include <tuple>
using namespace std;

//const int S = 5;  //introduce the size of the square matrix
const int S = 3;




void swap_(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap_(&arr[j], &arr[j+1]);
}



void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}




int find_first(int item, int l[S]){
    //function to find the first occurrence of <item> in array <l>
    int i = 0;
    while(item!= l[i]){
        i= i+1;

    if (i>S){return -1;}
    }
cout<<"found";
    return i;

}




int find_nth(int item, int l[S], int n){
    //function to find the nth occurrence of <item> in array <l>
int list_size;
list_size = sizeof(l);
int k = 0;
int i = 0;
while(k!= n)
        {

            if (item == l[i])
            {k++;}

            i++;
            if(i> list_size){return -1;}

        }
return i-1;

}


bool inlist(int item, int l[S]){
    // function to check if item is in l

int size_list;
size_list = sizeof(l);


int k = 0;

for(int i = 0; i<S;i++){
    if(item ==l[i])
        k++;
}
if(k==0){return false;}
else{return true;}
}


void sum_lines(int sums[S], int a_T[S][S]){
        for(int i=0;i<S;i++){
            cout<<endl;
            for(int j = 0; j<S; j++){
                sums[i] = sums[i]+a_T[i][j];
        }
    }

               }




void get_indexes(int sums[S], int sorted_sums[S], int indexes[S]){
  //function to return the indexes of the lines in their initial matrix
  // by the
  int item, k,idx;
  int count_0 = 0;
  for(int i = 0; i<S; i++){
    item = sorted_sums[i];

    k = 0;
    idx = -1;


    while(inlist(idx, indexes)){
        k++;
        idx = find_nth(item, sums, k);

        //if(idx==0 && count_0 == 0){count_0++;
        //break;}



    }
    indexes[i] = idx;


  }

}

void order_matrix_by_line_sum(int a_T[S][S], int ordered[S][S], int indexes[S]){
for(int i = 0;i<S;i++){
    int idx = indexes[i];
    for(int j = 0;j<S;j++){
        ordered[i][j] = a_T[idx][j];
    }
}

}






int max_score(vector<vector<int>> M , int ordered[S][S], vector<tuple<int, int>> pairs, int chosen_students[S], int stud_count){


if (M.size() == 2)
        {
            int proj1 = S-2;
            int proj2 = S-1;
            int stud1 =-1;
            int stud2 =-1;
            int search_list_1[S];
            int search_list_2[S];
            //populating the first search list
              for(int i = 0; i<S;i++){
                search_list_1[i] = ordered[proj1][i];
              }
            //populating the second search list
              for(int i = 0; i<S; i++){
                search_list_2[i] = ordered[proj2][i];
              }

            if(M[0][0]+M[1][1]>=M[0][1]+M[1][0])
            {


              int k1=2;
              stud1 = find_nth(M[0][0], search_list_1,1);


    if(inlist(stud1, chosen_students)==false){
        chosen_students[stud_count] = stud1;
        stud_count++;
    }
    else{
        while(inlist(stud1, chosen_students)){
            stud1 = find_nth(M[0][0], search_list_1, k1);
            k1++;
        }
        chosen_students[stud_count] = stud1;
        stud_count++;

    }


        int k2 = 2;
        stud2 = find_nth(M[1][1], search_list_2,1);

        if(inlist(stud2, chosen_students)==false){
            chosen_students[stud_count] = stud2;
            stud_count++;
        }
        else{while(inlist(stud2, chosen_students)){
            stud1 = find_nth(M[1][1], search_list_2, k2);
            k2++;
        }
        chosen_students[stud_count] = stud2;
        stud_count++;

        }

            }
            else{
            /*int stud1= -1;
            int stud2=-1;
            int k1=2;
            int k2 = 2;
            stud1 = find_nth(M[0][1], search_list_1,1);
            if(inlist(stud1, chosen_students)==false){
                chosen_students[stud_count] = stud1;
                stud_count++;
            }
            else{
                while(inlist(stud1, chosen_students)){
            stud1 = find_nth(M[0][1], search_list_1, k1);
            k1++;
        }
        chosen_students[stud_count] = stud1;
        stud_count++;
            }

            ///////
            stud2 = find_nth(M[1][0], search_list_2,1);

        if(inlist(stud2, chosen_students)==false){
            chosen_students[stud_count] = stud2;
            stud_count++;
        }
        else{while(inlist(stud2, chosen_students)){
            stud1 = find_nth(M[1][0], search_list_2, k2);
            k2++;
        }
        chosen_students[stud_count] = stud2;
        stud_count++;


            }*/



              int k1=2;
              stud1 = find_nth(M[1][0], search_list_1,1);


    if(inlist(stud1, chosen_students)==false){
        chosen_students[stud_count] = stud1;
        stud_count++;
    }
    else{
        while(inlist(stud1, chosen_students)){
            stud1 = find_nth(M[1][0], search_list_1, k1);
            k1++;
        }
        chosen_students[stud_count] = stud1;
        stud_count++;

    }


        int k2 = 2;
        stud2 = find_nth(M[0][1], search_list_2,1);

        if(inlist(stud2, chosen_students)==false){
            chosen_students[stud_count] = stud2;
            stud_count++;
        }
        else{while(inlist(stud2, chosen_students)){
            stud1 = find_nth(M[0][1], search_list_2, k2);
            k2++;
        }
        chosen_students[stud_count] = stud2;
        stud_count++;



            }


            pairs.emplace_back(stud1,proj1);
            pairs.emplace_back(stud2,proj2);

            cout<<"The final 2 pairs: "<<endl;
            cout<< stud1<<" "<<proj1<<endl;
            cout<<stud2<<" "<<proj2<<endl;

            return max(M[0][0] + M[1][1], M[0][1] + M[1][0] );}}

else
{
    int Size = M.size();
    int m = -1;
    int idx = -1;
    //find max of M[0]
    for (int i = 0; i<M.size(); i++){
    if(M[0][i]>=m){
        m = M[0][i];
        idx = i;
    }}
    int proj = S - M.size();
    int search_list[S];
    for(int i = 0; i<S;i++){
        search_list[i] = ordered[proj][i];
    }

    int k = 2;
    int stud = -1;
    stud = find_nth(m,search_list, 1);


//cout<<endl<<Size<<endl;


    if(inlist(stud, chosen_students)==false){
        chosen_students[stud_count] = stud;
        stud_count++;
    }
    else{
        while(inlist(stud, chosen_students)){
            stud = find_nth(m, search_list, k);
            k++;
        }
        chosen_students[stud_count] = stud;
        stud_count++;

    }


    //printArray(chosen_students,S);
    //cout<<endl<<"search_list = ";
    //printArray(search_list,S);


    pairs.emplace_back(stud,proj);




    //defining the new matrix



    int foo = 0;




    int new_size = Size-1;



    vector<vector<int>> new_mat( new_size , vector<int> (new_size, 0));




/*
   cout<<endl<<"M = ";
for(int i=0;i<new_mat.size()+1;i++){
            cout<<endl;
        for(int j = 0; j<new_mat.size()+1; j++){
            cout<<M[i][j]<<" ";
        }
    }
    */



//cout<<endl<<"idx = "<<idx<<" stud = "<<stud<<" proj = "<<proj<<" stud_count = "<<stud_count<<" m = "<<m<<endl;
cout<<"The pair no"<<stud_count<<endl;
cout<<stud<<" "<<proj<<endl;



for(int i = 0; i< Size -1 ; i++){

    foo = 0;
    for(int j = 0; j< Size ; j++){
            if(j==idx){continue;}


        new_mat[i][foo] = M[i+1][j];
        foo++;
    }
}


/*
cout<<endl<<endl<<"new_mat = ";
for(int i=0;i<new_mat.size();i++){
            cout<<endl;
        for(int j = 0; j<new_mat.size(); j++){
            cout<<new_mat[i][j]<<" ";
        }
    }

*/





return m+max_score(new_mat, ordered, pairs,chosen_students, stud_count);


}


}




int main()
{



  // int a[S][S] = {1,2,3,4,5,3,4,2,1,5,4,2,5,1,3,2,3,5,1,4,5,4,1,3,2};

   int a[S][S] = {1,2,3,3,1,2,2,3,1};
    int ordered[S][S];

    for(int i=0;i<S;i++){
            cout<<endl;
        for(int j = 0; j<S; j++){
            cout<<a[i][j]<<" ";
        }
    }


    //get the transpose
    int a_T[S][S];

    for(int i=0;i<S;i++){

        for(int j = 0; j<S; j++){
            a_T[i][j] = a[j][i];
        }
    }
cout<<endl;

        //print the transpose
       for(int i=0;i<S;i++){
            cout<<endl;
        for(int j = 0; j<S; j++){
            cout<<a_T[i][j]<<" ";
        }
    }

     cout<<endl;

    int sums[S];
    for(int i = 0; i<S; i++){
        sums[i] = 0;
    }



    sum_lines(sums, a_T);

   // cout<<endl<<"sums = ";

   // for(int i = 0;i<S;i++)
     //   cout<<sums[i]<<" ";



    int indexes[S];

    for(int i = 0; i<S; i++){
        indexes[i] = -1;
    }

    //printArray(indexes, S);



    int sorted_sums[S];
    for(int i = 0;i<S;i++){
        sorted_sums[i] = sums[i];
    }




    bubbleSort(sorted_sums, S);

    //printArray(sums, S);

    get_indexes(sums,sorted_sums, indexes);
   // cout<<"sorted_sums = ";
   // printArray(sorted_sums, S);

    //cout<<endl<<endl<<"indexes= ";
    //for(int i= 0;i<S;i++){
     //   cout<<indexes[i]<<" ";
    //}

    cout<<endl<<endl;

    order_matrix_by_line_sum(a_T,ordered, indexes);

      int ordered_copy[S][S];

    order_matrix_by_line_sum(a_T,ordered_copy, indexes);


    cout<<"the ordered matrix:"<<endl;

    for(int i=0;i<S;i++){
            cout<<endl;
        for(int j = 0; j<S; j++){
            cout<<ordered_copy[i][j]<<" ";
        }
    }




 // int test[3][3] = {1,2,3,4,5,6,7,8,9};
 // int index_test[3] = {2,1,0};
 // int a_t_test[3][3] = {1,2,3,4,5,6,7,8,9};


 // order_matrix_by_line_sum(a_t_test, test, index_test);





    vector<tuple<int, int>> pairs;


    int chosen_students[S];
    for(int i =0;i<S;i++){
        chosen_students[i]=-1;
    }

    int m;

    vector<vector<int>> M( S , vector<int> (S, 0));

    for(int i = 0;i<S;i++){
        for(int j = 0;j<S;j++){
            M[i][j]= ordered[i][j];
        }
    }





    cout<<endl<<endl<<endl<<"The Program Starts "<<endl;




//cout<<endl<<endl<<"the pairs are: ";



    m = max_score(M,ordered_copy, pairs, chosen_students, 0);

cout<<"The final score is = "<<m;

cout<<endl<<endl<<endl;

vector<tuple<int, int>> tup;

/////// diferent examples


cout<<"For the matrix "<<endl;

for(int i= 0; i<S; i++){
        cout<<endl;
    for(int j = 0; j<S; j++)
    {
        cout<<ordered[j][i]<<" ";
    }
}










    return 0;


    //need find element function




}
