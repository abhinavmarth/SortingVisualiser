#include <SDL2/SDL.h>
#include <iostream>
#include <random>
using namespace std;

void vis(vector<int>& arr,SDL_Renderer* renderer,unsigned int k,unsigned int j){
    unsigned int idx=0;
    for(int i : arr){
        if(idx == k){
            SDL_SetRenderDrawColor(renderer,255,0,0,100);
        }
        else if(idx == j){
            SDL_SetRenderDrawColor(renderer,0,0,255,100);
        }
        else{
              SDL_SetRenderDrawColor(renderer,255,255,255,100);
        }
        SDL_RenderDrawLine(renderer,idx,i,idx,80);
        idx+=1;
    }
}

//BUBBLE
void bubble(vector<int>& arr,SDL_Renderer* renderer){
for (unsigned int i = 0; i < arr.size(); i++) {
        for (unsigned int j = 0; j < arr.size()-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);

                SDL_SetRenderDrawColor(renderer, 0,0,0, 255);
                SDL_RenderClear(renderer);
                vis(arr, renderer, i, j);
                SDL_RenderPresent(renderer);
                SDL_Delay(10);
            }
        }
    }
}

//SELECTION
void selection(vector<int>& arr,SDL_Renderer* renderer){

    //finds the minimum element in unsorted vector
    for(unsigned int i=0;i<arr.size()-1;i++){
        unsigned int idx=i;
        for(unsigned int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[idx])idx=j;
        
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
        vis(arr,renderer,i,j);
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
        }
        if(idx!=i)swap(arr[i],arr[idx]); 
    }
}

//INSERTION
void insertion(vector<int>& arr,SDL_Renderer* renderer){

    unsigned int n = arr.size();
    for (unsigned int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
        vis(arr,renderer,i,j);
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
        }
        arr[j + 1] = key;
    }    
}

//MERGE

void merge(vector<int>& arr, int l, int m, int r,SDL_Renderer* renderer) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
        vis(arr,renderer,i,j);
        SDL_RenderPresent(renderer);
        SDL_Delay(20);
            i++;
        } else {
            arr[k] = R[j];
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
        vis(arr,renderer,i,j);
        SDL_RenderPresent(renderer);        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
        vis(arr,renderer,i,j);
        SDL_RenderPresent(renderer);
        SDL_Delay(20);
        SDL_Delay(20);
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
        vis(arr,renderer,-1,j);
        SDL_RenderPresent(renderer);
        SDL_Delay(20);
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
        vis(arr,renderer,-1,j);
        SDL_RenderPresent(renderer);
        SDL_Delay(20);
        j++;
        k++;
    }
}
void mergesort(vector<int>& arr,SDL_Renderer* renderer,int low ,int high){
    if(low<high){
        int mid = low+(high-low)/2;
        mergesort(arr,renderer,low,mid);
        mergesort(arr,renderer,mid+1,high);
        merge(arr,low,mid,high,renderer);
    }
}

//QUICK SORT
int quicksort(vector<int>& arr,int low,int high,SDL_Renderer* renderer){
    int pivot = arr[high];
    int i = low - 1,j;

    for ( j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
        vis(arr,renderer,i,j);
        SDL_RenderPresent(renderer);
        SDL_Delay(20);
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quick(vector<int>& arr,int low,int high,SDL_Renderer* renderer){
   if(low<high)
{    int part = quicksort(arr,low,high,renderer);
    quick(arr,low,part-1,renderer);
    quick(arr,part+1,high,renderer);
    }
}
int main(){

    //CREATING RANDOM NUMBERS
    SDL_Init(SDL_INIT_VIDEO);
    random_device rd;
    uniform_int_distribution<int> d(1,50);
    vector<int> arr;
    for(int i=1;i<=50;i++){
        arr.push_back(d(rd));
        cout<<arr[i]<<" ";
    }
    
    int ch;
    cout<<endl;
    cout<<"1 : BUBBLE"<<endl;
    cout<<"2 : SELECTION"<<endl;
    cout<<"3 : INSERTION"<<endl;
    cout<<"4 : MERGE"<<endl;
    cout<<"5 : QUICK"<<endl;
    cin>>ch;

SDL_Window* window = SDL_CreateWindow("SORTING VISUALIZER", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 100*10, 50*10, SDL_WINDOW_FULLSCREEN);
SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
SDL_RenderSetScale(renderer, 10, 10);
    switch (ch)
    {
    case 1: bubble(arr,renderer);
            break;
    case 2: selection(arr,renderer);
            break;
    case 3: insertion(arr,renderer);
            break;
    case 4: mergesort(arr,renderer,0,arr.size());
            break; 
    case 5: quick(arr,0,arr.size(),renderer);
            break;
    default: cout<<"NOT VALID";
        break;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

