/*************************************************************************
    > File Name: 109.c
    > Author: duqinglong
    > Mail: du_303412@163.com 
    > Created Time: Fri 04 Mar 2016 10:23:11 AM CST
 ************************************************************************/

/**
 * Definition for singly-linked list
 * struct ListNode {
 *		int val;
 *		struct ListNode* next;
 * };
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *		int val;
 *		struct TreeNode *left;
 *		struct TreeNode *right;
 * };
 */

struct TreeNode* sortedListToBST(struct ListNode* head) {
	struct ListNode* first, *second, *temp = NULL;
	struct TreeNode* root;
	if (head == NULL)
		return NULL;
	else if (head->next == NULL)
	{
		if ((root = (struct TreeNode*)malloc(sizeof(struct TreeNode))) == NULL)
			return NULL;
		root->val = head->val;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	first = head, second = head;
	while (first != NULL && second != NULL)
	{
		temp = second;
		first = first->next->next;
		second = second->next;
	}
	if (temp != NULL)
		temp->next = NULL;
	if ((root = (struct TreeNode*)malloc(sizeof(struct TreeNode))) == NULL)
		return NULL;
	root->val = second->val;
	root->left = sortedListToBST(head);
	root->right = sortedListToBST(second->next);
	return root;
}
