#pragma once

#include "alpch.h"

namespace Algorify
{
	namespace DataStructures
	{
		template<typename T>
		class LinkedList
		{
		public:
			LinkedList();
			~LinkedList();

			T& operator[](int index);
			void operator=(std::initializer_list<T>& input);

			void Append(const T& value);
			void Remove(const T& value);

			void Clear();
			int Size();

		private:
			struct Node
			{
				T data;
				Node* back;
				Node* forw;

				Node(const T& value) : data(value), back(nullptr), forw(nullptr) {};
				Node() : data(NULL), back(nullptr), forw(nullptr) {};
			};

			Node* GetNode(int& index);
			void DestroyList(Node* n);

			Node* Head;
			int size = 0;
		};

		template<typename T>
		LinkedList<T>::LinkedList()
		{
			size = 0;
		}

		template<typename T>
		LinkedList<T>::~LinkedList()
		{
			if (Head != nullptr)
			{
				DestroyList(Head);
			}
		}

		template<typename T>
		T& LinkedList<T>::operator[](int index)
		{
			if (index > size || index < 0)
			{
				throw std::out_of_range("Index outside the bounds of the list");
			}

			Node* n = Head;

			for (int i = 0; i < index; i++)
			{
				if (n->forw == nullptr)
				{
					break;
				}

				n = n->forw;
			}

			return n->data;
		}

		template<typename T>
		void LinkedList<T>::operator=(std::initializer_list<T>& input)
		{
			this->size = input.size;

			if (Head == nullptr)
			{
				Head = new Node();
			}

			Node* n = Head;

			for (int i = 0; i < size; i++)
			{
				if (n == nullptr)
				{
					continue;
				}

				n->data = input[i];

				if (n->forw)
				{
					n = n->forw;
				}
			}
		}

		template<typename T>
		void LinkedList<T>::Append(const T& value)
		{
			size++;

			if (Head == NULL)
			{
				Head = new Node(value);
				return;
			}

			Node* endNode = this->GetNode(size);

			endNode->forw = new Node(value);
		}

		template<typename T>
		void LinkedList<T>::Clear()
		{
			if (Head != nullptr)
			{
				DestroyList(Head);
				size = 0;
			}
		}

		template<typename T>
		int LinkedList<T>::Size()
		{
			return size + 1;
		}

		template<typename T>
		typename LinkedList<T>::Node* LinkedList<T>::GetNode(int& index)
		{
			if (Head == nullptr || index < 0)
			{
				return nullptr;
			}

			if (index > size)
			{
				throw std::out_of_range("Index outside the bounds of the list");
			}

			Node* n = Head;

			for (int i = 0; i < index; i++)
			{
				if (n->forw == nullptr)
				{
					break;
				}

				n = n->forw;
			}

			return n;
		}

		template<typename T>
		void LinkedList<T>::DestroyList(Node* n)
		{	
			if (n->forw != nullptr)
			{
				DestroyList(n->forw);
			}

			delete n;
		}

	}
}