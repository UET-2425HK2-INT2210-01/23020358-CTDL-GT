#include<iostream>
#include<vector>
using std::vector,std::cout;
class Min_heap {
    private:
        int size;
        int lastindex;
        vector<int> arr;

        int parent(int i) {
            return i/2;
        }

        int leftchild(int i) {
            return 2 * i;
        }

        int rightchild(int i) {
            return 2 * i + 1;
        }

        void swap(int a, int b) {
            int temp = a;
            a = b;
            b = temp;
        }

        void diveup(int i) {
            while(i != 1 && arr[parent(i)] > arr[i]) {
                swap(arr[parent(i)],arr[i]);
                i = parent(i);
            }   
        }

        void sinkdown(int i) {
            int maxIndex = i;
            int l = leftchild(i);
            if (l <= size && arr[l] > arr[maxIndex])
                maxIndex = l;
            int r = rightchild(i);
            if (r <= size && arr[r] > arr[maxIndex]) 
                maxIndex = r;
            if (i != maxIndex) {
                swap(arr[i], arr[maxIndex]);
                sinkdown(maxIndex);
            }
        }
    public:
        Min_heap(int n) {
            size = n + 1;
            lastindex = 1;
            arr.resize(size);
        }
        
        void insert(int val) {
            arr[lastindex] = val;
            diveup(lastindex);
            lastindex++;
        }

        void del(int val) {
            for (int i = 1; i < lastindex; i++) {
                if (arr[i] == val) {
                    swap(arr[i], arr[lastindex]);
                    sinkdown(i);
                    break;
                }
            }
        }
};
