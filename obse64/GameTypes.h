#pragma once

#include "obse64_common/Types.h"

// base types/containers

// 10
template <typename T>
class BSSimpleList
{
public:
	struct Node
	{
		T		m_data;
		Node	* m_next;
	};

	Node node;

    // iterator support.

    class iterator
    {
    public:
        T& operator*() const { return node_->m_data; }
        T* operator->() { return &(node_->m_data); }

        bool operator==(const iterator other) const { return other.node_ == node_; }
        bool operator!=(const iterator other) const { return !(other == *this); }

        iterator operator++()
        {
            node_ = node_->m_next;
            return *this;
        }

    private:
        friend class BSSimpleList;

        iterator(Node* node) : node_(node) {}

        Node* node_;
    };

    iterator begin() { return iterator{ &node }; }
    iterator end() { return iterator{ nullptr }; }

    class const_iterator
    {
    public:
        const T& operator*() const { return node_->m_data; }
        const T* operator->() { return &(node_->m_data); }

        bool operator==(const const_iterator other) const { return other.node_ == node_; }
        bool operator!=(const const_iterator other) const { return !(other == *this); }

        const_iterator operator++()
        {
            node_ = node_->m_next;
            return *this;
        }

    private:
        friend class BSSimpleList;

        const_iterator(const Node* node) : node_(node) {}

        const Node* node_;
    };
    
    const_iterator begin() const { return const_iterator{ &node }; }
    const_iterator end() const { return const_iterator{ nullptr }; }
};

static_assert(sizeof(BSSimpleList<void *>) == 0x10);

// 10
class BSStringT
{
public:
	char	* m_data;	// 0
	u16		m_dataLen;	// 8
	u16		m_bufLen;	// A
};

static_assert(sizeof(BSStringT) == 0x10);
