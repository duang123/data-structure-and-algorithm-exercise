#include<vector>
#include<iostream>
using namespace std;

int find(vector<int>&v,int low,int high){
	auto tmp=v[low];
	int i=low+1,j=high;
	while(i<j){
		while(i<=high && v[i]<tmp)++i;
		if(i>j)break;
		while(j>=low && v[j]>=tmp)--j;
		if(i<j){
			swap(v[i],v[j]);
		}
	}
	swap(v[low],v[j]);
	return j;
}

void qsort_(vector<int>&v,int low,int high){
	if(low>=high)return;
	auto pivot=find(v,low,high);
	qsort_(v,low,pivot-1);
	qsort_(v,pivot+1,high);
	return;
}

void qsort(vector<int>&v){
	if(v.size()<=1)return;
	qsort_(v,0,v.size()-1);
}

void printV(vector<int>&v){
	for(auto c:v)
		cout<<c<<",";
	cout<<endl;
}

int main(){
	vector<int>v{4,2,3,9,5,7};
	qsort(v);
	printV(v);
}
