#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

struct MinHeapNode
{
	char data;
	unsigned freq;
	MinHeapNode* left;
	MinHeapNode* right;
	MinHeapNode(char data, unsigned freq)
	{
		left = right = NULL;
		this->left = left;
		this->right = right;
	}
};

struct compare
{
	bool operator()(MinHeapNode* left, MinHeapNode* right)
	{
		return(left->freq > right->freq);
	}
};

void printNodes(struct MinHeapNode* root, string str)
{
	if (!root)
	{
		return;
	}
	if (root->data != '$')
	{
		cout << root->data << "." << str << endl;
	}
	printNodes(root->left, str + '0');
	printNodes(root->right, str + '1');
}

void HuffmanCodes(char arr[], int freq[], int size)
{
	struct MinHeapNode* left, * right, * top;
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare>minHeap;
	for (int i = 0;i < size;i++)
	{
		minHeap.push(new MinHeapNode(arr[i], freq[i]));
	}
	while (minHeap.size() != 1)
	{
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		top = new MinHeapNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);

	}
	printNodes(minHeap.top(),"");
}

int main()
{
	char arr[] = { 'a','b','c','d','e','f' };
	int freq[] = { 5,6,13,14,16,45 };
	int size = sizeof(arr) / sizeof(arr[0]);
	HuffmanCodes(arr, freq, size);
	return 0;
}