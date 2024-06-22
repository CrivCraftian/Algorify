#pragma once

namespace Algorify
{
	namespace DataStructures
	{

		template<typename T>
		class BinaryTree
		{
		public:

			void Insert(const T& value);
			bool Search(const T& value);

			bool IsEmpty();
			void Clear();

			~BinaryTree();

		private:
			struct Node
			{
			public:
				T data;
				Node* left;
				Node* right;
				Node(const T& value) : data(value), left(nullptr), right(nullptr) {};
			};

			Node* root;
			void DeleteTree(Node* node);


		};

		/// <summary>
		/// Inserts an element into the tree,
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="value"></param>
		template<typename T>
		void BinaryTree<T>::Insert(const T& value)
		{
			if (root == NULL)
			{
				std::cout << "Root Node Added" << "\n";
				root = new Node(value);
				return;
			}

			std::queue<Node*> q;
			q.push(root);

			while (!q.empty())
			{
				Node* temp = q.front();
				q.pop();

				if (temp->left == nullptr)
				{
					std::cout << "Left Node Added" << "\n";

					temp->left = new Node(value);
					break;
				}
				else
				{
					q.push(temp->left);
				}

				if (temp->right == nullptr)
				{
					std::cout << "Right Node Added" << "\n";
					temp->right = new Node(value);
					break;
				}
				else
				{
					q.push(temp->right);
				}
			}
		}

		/// <summary>
		/// Searches the tree for the given value
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="value">Value you search for</param>
		/// <returns>Returns true if element exists within tree</returns>
		template<typename T>
		bool BinaryTree<T>::Search(const T& value)
		{
			if (root == NULL)
			{
				return false;
			}

			std::queue<Node*> Q;
			Q.push(root);

			while (!Q.empty())
			{
				Node* current = Q.front();
				Q.pop();

				if (current->data == value)
				{
					return true;
				}

				if (current->left != nullptr)
				{
					Q.push(current->left);
				}

				if (current->right != nullptr)
				{
					Q.push(current->right);
				}
			}

			return false;
		}

		/// <summary>
		/// 
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <returns>Returns true if tree is empty</returns>
		template<typename T>
		bool BinaryTree<T>::IsEmpty()
		{
			if (root == NULL)
			{
				return true;
			}

			return false;
		}

		/// <summary>
		/// Clears Tree and deletes all child nodes
		/// </summary>
		/// <typeparam name="T"></typeparam>
		template<typename T>
		void BinaryTree<T>::Clear()
		{
			if (IsEmpty())
			{
				return;
			}

			DeleteTree(root);

			root = nullptr;
		}

		template<typename T>
		BinaryTree<T>::~BinaryTree()
		{
			if (root != NULL)
			{
				DeleteTree(root);
			}
		}

		template<typename T>
		void BinaryTree<T>::DeleteTree(Node* node)
		{
			if (node != nullptr)
			{
				DeleteTree(node->left);
				DeleteTree(node->right);

				delete node;
			}
		}

	}
}