/*Problem Statement #
Given an array of positive numbers and a positive number ‘S’, find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’. Return 0, if no such subarray exists.*/
// you have to find the minimum sized subarray with sum k
// utkarsh bhaiya ne bola tha 2 loop wale more specifically for loop wale sliding window 
// ka template istamal karo
int minSubarray(int arr[],int sum,int n)
{
    int startWindow=0;
    int endWindow=0;
    int ans=0;
    int realans=n;
    for(endWindow=0;endWindow<n;endWindow++)
    {
        // yahan par hain matlab add karna jaruri
        ans+=arr[endWindow]++;
        // add karte jayenge karte jayenge jab tak ans >= sum na ho jaye 
        while(ans>=sum)
        {
            // sabse pehle answer store
            realans= min(realans,endWindow-startWindow+1);
            ans-=arr[startWindow];
            startWindow++;
            //endWindow to apne aap plus hote jayega
           
        }
    }
}
// basic format of sliding window