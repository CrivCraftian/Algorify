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
			LinkedList(std::initializer_list<T> values);
			LinkedList();
			~LinkedList();

			T& operator[](int index);

			void Append(const T& value);
			void Remove(const int index);

			void Clear();
			int Size();

			std::string ToString();
		private:
			struct Node
			{
				T data;
				Node* back;
				Node* forw;

				Node(const T& value) : data(value), back(nullptr), forw(nullptr) {};
				Node() : data(NULL), back(nullptr), forw(nullptr) {};
			};

			Node* GetNode(int index);
			void DestroyList(Node* n);

			void ValidateIndex(const int& index) const;

			Node* Head;
			int size = 0;
		};

		template<typename T>
		LinkedList<T>::LinkedList(std::initializer_list<T> values) : Head(nullptr), size(0)
		{
			for (const T& value : values)
			{
				Append(value);
			}
		}

		template<typename T>
		LinkedList<T>::LinkedList() : Head(nullptr), size(0)
		{

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
			return GetNode(index)->data;
		}

		template<typename T>
		void LinkedList<T>::Append(const T& value)
		{
			Node* newNode = new Node(value);

			if (Head == NULL)
			{
				Head = newNode;
				size++;
				return;
			}

			Node* endNode = this->GetNode(size-1);

			newNode->back = endNode;

			endNode->forw = newNode;

			size++;
		}

		template<typename T>
		void LinkedList<T>::Remove(const int index)
		{
			ValidateIndex(index);

			Node* current = GetNode(index);
			
			if (current == nullptr)
			{
				return;
			}

			size--;

			if (current->back != nullptr)
			{
				current->back->forw = current->forw;
			}

			if(current->forw != nullptr)
			{
				current->forw->back = current->back;
			}

			if (current == Head)
			{
				if (current->forw != nullptr)
				{
					Head = current->forw;
				}
			}

			delete current;
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
			return size;
		}

		template<typename T>
		std::string LinkedList<T>::ToString()
		{
			std::ostringstream output;

			for (int i = 0; i < size; i++)
			{
				output << GetNode(i)->data << ", ";
			}

			output << "\n ";

			return output.str();
		}

		template<typename T>
		typename LinkedList<T>::Node* LinkedList<T>::GetNode(int index)
		{
			ValidateIndex(index);

			if (Head == nullptr || index < 0)
			{
				return nullptr;
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

		template<typename T>
		void LinkedList<T>::ValidateIndex(const int& index) const
		{
			if (index > size || index < 0)
			{
				throw std::out_of_range("Index outside the bounds of the list");
			}
		}

	}
}