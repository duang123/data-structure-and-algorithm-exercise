#include<vector>
#include<iostream>
using namespace std;

void merge(vector<int>&v,int low,int mid,int high){
	vector<int>tmp;
	int i=low,j=mid+1,k=0;
	while(i<=mid && j<=high){
		if(v[i]<v[j]){
			tmp.push_back(v[i++]);
		}else tmp.push_back(v[j++]);
	}
	while(i<=mid){
		tmp.push_back(v[i++]);
	}
	while(j<=high){
		tmp.push_back(v[j++]);
	}
	for(int i=low;i<=high;++i){
		v[i]=tmp[k++];
	}
}

void mergesort_(vector<int>&v,int low,int high){
	if(low>=high)return;
	auto mid=low+(high-low)/2;
	mergesort_(v,low,mid);
	mergesort_(v,mid+1,high);
	merge(v,low,mid,high);
	return;
}

void mergeSort(vector<int>&v){
	if(v.size()<=1)return;
	mergesort_(v,0,v.size()-1);
}

void printV(vector<int>&v){
	for(auto c:v)
		cout<<c<<",";
	cout<<endl;
}

int main(){
	vector<int>v{4,2,3,9,5,7};
	mergeSort(v);
	printV(v);
}
