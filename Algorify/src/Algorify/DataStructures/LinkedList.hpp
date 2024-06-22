#pragma once

#include "alpch.h"

namespace Algorify
{
	namespace DataStructures
	{
		/** 
		* @brief A class that stores linked data in a list format
		* @param T Type of data stored in list
		*/ 

		template<typename T>
		class LinkedList
		{
		public:
			LinkedList(std::initializer_list<T> values);
			LinkedList();
			~LinkedList();

			/// <summary>
			/// Adds element to beginning of the list
			/// </summary>
			/// <param name="value">Value being inserted</param>
			void Prepend(const T& value);

			/// <summary>
			/// Adds element to end of the list
			/// </summary>
			/// <param name="value">Value being inserted</param>
			void Append(const T& value);

			/// <summary>
			/// Inserts the element at the given index
			/// </summary>
			/// <param name="index">Index of insertion</param>
			/// <param name="value">Value being inserted</param>
			void Insert(const int& index, const T& value);

			/// <summary>
			/// Removes element at given index
			/// </summary>
			/// <param name="index">Index of removal</param>
			void Remove(const int index);

			int Search(const T& value);

			/// <summary>
			/// Returns the first element in the list
			/// </summary>
			/// <returns></returns>
			T& GetFirst();

			/// <summary>
			/// Returns the last element in the list
			/// </summary>
			/// <returns></returns>
			T& GetLast();

			/// <summary>
			/// Clears the list of all values
			/// </summary>
			void Clear();

			/// <summary>
			/// Returns the size of the list
			/// </summary>
			/// <returns></returns>
			int Size();

			T& operator[](int index);
			LinkedList<T>& operator=(const LinkedList& other);
			bool operator==(const LinkedList<T>& other) const;
			bool operator!=(const LinkedList<T>& other) const;

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

			Node* GetNode(const int& index);
			void InsertNode(const int& index, Node* node);

			Node* Copy(const Node* head);

			void DestroyList(Node* n);

			void ValidateIndex(const int& index) const;

			Node* Head;
			Node* Tail;
			int size = 0;
		};

		template<typename T>
		LinkedList<T>::LinkedList(std::initializer_list<T> values) : Head(nullptr), Tail(nullptr), size(0)
		{
			for (const T& value : values)
			{
				Append(value);
			}
		}

		template<typename T>
		LinkedList<T>::LinkedList() : Head(nullptr), Tail(nullptr), size(0)
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
		LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
		{
			if (this != &other)
			{
				Clear();
				this->Head = Copy(other.Head);
				size = other.size;
			}
			return *this;
		}

		template<typename T>
		void LinkedList<T>::Prepend(const T& value)
		{
			Node* newNode = new Node(value);

			if (Head == nullptr && Tail == nullptr)
			{
				Head = newNode;
				Tail = newNode;
				size++;
				return;
			}

			Head->back = newNode;
			newNode->forw = Head;
			Head = newNode;

			size++;
		}

		template<typename T>
		void LinkedList<T>::Append(const T& value)
		{
			Node* newNode = new Node(value);

			if (Head == nullptr && Tail == nullptr)
			{
				Head = newNode;
				Tail = newNode;
				size++;
				return;
			}

			Tail->forw = newNode;
			newNode->back = Tail;
			Tail = newNode;

			size++;
		}

		template<typename T>
		void LinkedList<T>::Insert(const int& index, const T& value)
		{
			ValidateIndex(index);

			InsertNode(index, new Node(value));
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
		int LinkedList<T>::Search(const T& value)
		{
			if (Head == nullptr)
			{
				std::out_of_range("List is empty");
			}

			Node* current = Head;

			for (int i = 0; i < size; i++)
			{
				if (current == nullptr)
				{
					continue;
				}

				if (current->data == value)
				{
					return i;
				}
				current = current->forw;
			}

			return -1;
		}

		template<typename T>
		T& LinkedList<T>::GetFirst()
		{
			if (Head != nullptr)
			{
				return Head->data;
			}
			else
			{
				return NULL;
			}
		}

		template<typename T>
		T& LinkedList<T>::GetLast()
		{
			if (Tail != nullptr)
			{
				return Tail->data;
			}
			else
			{
				return NULL;
			}
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
		bool LinkedList<T>::operator==(const LinkedList<T>& other) const
		{
			if (size != other.size)
			{
				return false;
			}

			Node* current1 = Head;
			Node* current2 = other.Head;

			while (current1 != nullptr && current2 != nullptr)
			{
				if (current1->data != current2->data)
				{
					return false;
				}

				current1 = current1->forw;
				current2 = current2->forw;
			}

			return true;
		}

		template<typename T>
		bool LinkedList<T>::operator!=(const LinkedList<T>& other) const
		{
			return !(*this == other);
		}

		template<typename T>
		std::string LinkedList<T>::ToString()
		{
			std::ostringstream output;

			for (int i = 0; i < size; i++)
			{
				output << GetNode(i)->data;

				if (i == size-1)
				{
					continue;
				}

				output << ", ";
			}

			output << "\n ";

			return output.str();
		}

		template<typename T>
		typename LinkedList<T>::Node* LinkedList<T>::GetNode(const int& index)
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
		void LinkedList<T>::InsertNode(const int& index, Node* node)
		{
			ValidateIndex(index);

			Node* replaced = GetNode(index);

			if (index == 0)
			{
				Head = node;
			}

			if (index == size)
			{
				Tail = node;
			}

			if (replaced != nullptr)
			{
				node->forw = replaced;
			}
			else
			{
				node->forw = nullptr;
			}

			if (replaced != nullptr)
			{
				if (replaced->back != nullptr)
				{
					node->back = replaced->back;

					if (replaced->back->back != nullptr)
					{
						replaced->back->forw = node;
					}

					replaced->back = node;
				}
				else
				{
					node->back = nullptr;
				}
			}

			size++;
		}

		template<typename T>
		typename LinkedList<T>::Node* LinkedList<T>::Copy(const Node* head)
		{
			if (head == nullptr)
			{
				return nullptr;
			}

			Node* newHead = new Node(head->data);
			Node* current = newHead;
			Node* otherCurrent = head->forw;

			while (otherCurrent != nullptr)
			{
				Node* newNode = new Node(otherCurrent->data);
				current->forw = newNode;
				current->forw->back = current;

				if (current->forw == nullptr)
				{
					Tail = newNode;
				}

				current = current->forw;
				otherCurrent = otherCurrent->forw;
			}

			return newHead;
		}

		template<typename T>
		void LinkedList<T>::DestroyList(Node* n)
		{	
			if (n->forw != nullptr)
			{
				DestroyList(n->forw);
			}

			delete n;
			n = nullptr;
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