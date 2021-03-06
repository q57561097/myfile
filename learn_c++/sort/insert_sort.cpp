#include<iostream>
#define size 10
using namespace std;

int list[size] = {1,3,2,4,6,5,7,8,9,0};

void print_list(int nums[], int n){
	int i;
	for (i=0;i<n;i++) cout<<nums[i]<<endl;
}

void insert_sort(int nums[], int n){
	int i, j, k;
	for (i=1;i<size;i++){
		for (j=i-1;j>=0;j--){
			if(nums[i]>=nums[j]) break;
		}
		int temp = nums[i];
		for (k=i-1;k>j;k--) nums[k+1]=nums[k];
		nums[j+1]=temp;
}
 print_list(nums, n);       
}


void shell_insert(int nums[], int dk, int n){
	int i,j,k, temp;
	for (i=dk;i<n;i=i+dk){
		for (j=i-dk;j>=0;j=j-dk){
			if (nums[j]<=nums[i]) break;
		}
		temp = nums[i];
		for (k=i-dk;k>j;k=k-dk) nums[k+dk]=nums[k];
		nums[j+dk]=temp;

	}

}

void shell_sort(int nums[], int n){
	int dks[4] ={8,4,2,1};
	int j;
	for (j=0;j<4;j++) shell_insert(nums, dks[j], n);
	//shell_insert(nums, 2, n);
	print_list(nums, n);

}

void bubble_sort(int nums[], int n){
	print_list(nums,n);
	cout<<"sorted"<<endl;
	int i, j, temp;
	for (i=0;i<n;i++){
		for (j=n-1;j>i;j--){
			if (nums[j-1]>nums[j]){
				temp=nums[j];
				nums[j]=nums[j-1];
				nums[j-1] = temp;
			}

			}
	
		}
	print_list(nums, n);
}

int partition(int nums[], int start, int end){
   int temp = nums[start];
	while (start<end){
	while (nums[end]>=temp&&start<end) end--;
	if (start<end) nums[start++]=nums[end];
	while (nums[start]<=temp&&start<end) start++;
	if (start<end) nums[end--]=nums[start];
}
nums[start]=temp;
return start;
}
void quick_sort(int nums[], int start, int end){
	if (start<end){
	int p = partition(nums, start, end);
	//cout<<p<<"||"<<endl;
	//print_list(nums,size);
	quick_sort(nums, start, p-1);
	quick_sort(nums,p+1, end);
	
}
}
void select_sort(int nums[], int n){
	int temp,i,j, k;
	for (i=0;i<n;i++){
		k=i;
		for(j=n-1;j>i;j--) {
		if (nums[j]<nums[k]) k=j;
		}
		temp = nums[k];
		nums[k]=nums[i];
		nums[i]= temp;
	}
	cout<<"select_sort"<<endl;
	print_list(list, size);	
}

void sift(int nums[], int i, int n){
int j, temp;
//取数据时从零开始
temp = nums[i-1];
j=i*2;
while (j<=n){
	if (nums[j-1]<nums[j]&&j<n) j++;
	if (nums[j-1]<=temp) break;
	nums[i-1]=nums[j-1];
	i=j; 
	j=i*2;
	}
nums[i-1]=temp;
}

void sift_sort(int nums[], int n){
int j,i, temp;
for (i=n/2;i>0;i--) sift(nums, i, n);
for (j=n;j>1;j--){	
	temp = nums[j-1];	
	nums[j-1]=nums[0];
	nums[0]=temp;
	sift(nums, 1, j-1);	
	
}
print_list(list, size);
}

void merge(int nums[], int start, int mid, int end){
	int *temp;
	temp  = new int[end-start+1];
	int i=start, j=mid+1, k=0;
	while (i<=mid&&j<=end){
		if (nums[i]<nums[j]) temp[k++] = nums[i++];
		else temp[k++] = nums[j++];

	}
	while (i<=mid) temp[k++]=nums[i++];
	while (j<=end) temp[k++]=nums[j++];
	for (i=start;i<=end;i++) nums[i]=temp[i-start];
	delete []temp;
}

void merge_pass(int nums[], int len, int n){
	int mid, end, i=0;
	while (i<n){
		mid = i+len-1;
		if (mid>n) break;
		else {
			end = mid+len;
			if (end>=n) end = n-1;
			merge(nums, i, mid, end);
			i=end+1;
			}	
	}	
	}

void merge_sort(int nums[], int n){
 	int len=1;
	while (len <n){
		merge_pass(nums, len, n);
		len = len*2;
		//merge_pass(nums, len, n);
		//len = len*2;
	
            }
	print_list(nums, n);
}
int main(){
	//直接插入排序
	//insert_sort(list, size);
	//希尔排序
	//shell_sort(list, size);
	//冒泡排序
	//bubble_sort(list, size);
	//快速排序
	//quick_sort(list, 0, size-1);
	//直接选择排序
	//select_sort(list, size);
	//堆排序
	//sift_sort(list, size);
	//归并排序
	merge_sort(list,size);
	//print_list(list, size);
}
