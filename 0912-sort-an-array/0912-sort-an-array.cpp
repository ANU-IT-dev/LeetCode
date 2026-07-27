class Solution {
public:
    void merge(vector<int>&arr, int l,  int m ,int r)
    {
        int n1= m-l+1;
        int n2= r-m;
        int L[n1] ,R[n2];
        int k=l;
        // fill L

        for(int i=0; i<n1; i++)
        {
            L[i]=arr[k];
            k++;
        }

        // fill R
        for(int i=0; i<n2; i++)
        {
            R[i]=arr[k];
            k++;
        }

        //merge them in arr;
         int i=0; int j=0; k=l;
         while(i<n1 && j<n2)
         {
            if(L[i]<=R[j])
            {
                arr[k]=L[i];
                i++;
            }
            else
            {
                arr[k]=R[j];
                j++;

            }
            k++;
         }
         while(i<n1)
         {
            arr[k]= L[i];
            i++;
            k++;
         }
         while(j<n2)
         {
            arr[k]= R[j];
            j++;
            k++;
         }
    }
    void mergesort(vector<int>&arr, int l,int r)
    {
        if(l>=r)
        {
            return;

        }
        int mid = l+(r-l)/2;
       mergesort(arr,l,mid);
       mergesort(arr,mid+1 ,r);

        merge(arr,l,mid,r);
    }

    vector<int> sortArray(vector<int>& nums)
    {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
};