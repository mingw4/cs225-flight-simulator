
/**
 * @file heap.cpp
 * Implementation of a heap class.
 */

// template <class T, class Compare>
#include "heap.h"
size_t heap::root() const
{
    return 1;
    // @TODO Update to return the index you are choosing to be your root.
}

// template <class T, class Compare>
size_t heap::leftChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the left child.
    return currentIdx * 2;
}

// template <class T, class Compare>
size_t heap::rightChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the right child.
    return currentIdx * 2 + 1;
}

// template <class T, class Compare>
size_t heap::parent(size_t currentIdx) const
{
    // @TODO Update to return the index of the parent.
    return floor(currentIdx / 2);
}

// template <class T, class Compare>
bool heap::hasAChild(size_t currentIdx) const
{
    if ((currentIdx * 2) < _elems.size()) {
        return true;
    }
    return false;
    // @TODO Update to return whether the given node has a child
}

// template <class T, class Compare>
size_t heap::maxPriorityChild(size_t currentIdx) const
{
    return 1;
    // @TODO Update to return the index of the child with highest priority
    ///   as defined by higherPriority()
}

// template <class T, class Compare>
void heap::heapifyDown(size_t currentIdx)
{
    size_t curr = currentIdx;
    if (!hasAChild(currentIdx)) {
        return;
    }
    if ((leftChild(currentIdx) < _elems.size()) && (smaller(_elems[leftChild(currentIdx)], _elems[curr]))) {
        curr = leftChild(currentIdx);
    }
    if ((rightChild(currentIdx) < _elems.size()) && (smaller(_elems[rightChild(currentIdx)], _elems[curr]))) {
        curr = rightChild(currentIdx);
    }
    if (curr == currentIdx) {
        return;
    }
    swap(_elems[currentIdx], _elems[curr]);
    heapifyDown(curr);
    // @TODO Implement the heapifyDown algorithm.
}

// template <class T, class Compare>
void heap::heapifyUp(size_t currentIdx)
{
    if (currentIdx == root())
        return;
    size_t parentIdx = parent(currentIdx);
    if (smaller(_elems[currentIdx], _elems[parentIdx])) {
        std::swap(_elems[currentIdx], _elems[parentIdx]);
        heapifyUp(parentIdx);
    }
}

// template <class T, class Compare>
heap::heap()
{
    _elems.push_back(NULL);
    // @TODO Depending on your implementation, this function may or may
    ///   not need modifying
}

// template <class T, class Compare>
heap::heap(const std::vector<Node*>& elems) 
{
    _elems.push_back(NULL);
    for (unsigned i = 0; i < elems.size(); i++) {
        _elems.push_back(elems[i]);
    }
    for (unsigned i = _elems.size() - 1; i >= 1; i--) {
        heapifyDown(i);
    }
    // @TODO Construct a heap using the buildHeap algorithm
}

// template <class T, class Compare>
Node* heap::pop()
{
    if (!empty()) {
        Node* toReturn = _elems[1];
        swap(_elems[1], _elems[_elems.size() - 1]);
        _elems.erase(_elems.begin() + _elems.size() - 1);
        heapifyDown(1);
        return toReturn;
    }
    // @TODO Remove, and return, the element with highest priority
    return NULL;
}

// template <class T, class Compare>
Node* heap::peek() const
{
    if (!empty()) {
        return _elems[1];
    } else {
        return NULL;
    }
    // @TODO Return, but do not remove, the element with highest priority
}

// template <class T, class Compare>
void heap::push(Node* elem)
{
    Node* temp = elem;
    _elems.push_back(temp);
    heapifyUp(_elems.size() - 1);
    // @TODO Add elem to the heap
}

// template <class T, class Compare>
void heap::updateElem(const size_t & idx, Node* elem)
{
    size_t curr = idx;
    _elems[curr] = elem;
    while (curr >= 1) {
        heapifyDown(curr);
        curr = parent(curr);
    }
    // @TODO In-place updates the value stored in the heap array at idx
    // Corrects the heap to remain as a valid heap even after update
}


// template <class T, class Compare>
bool heap::empty() const
{
    if (_elems.size() <= 1) {
        return true;
    }
    // @TODO Determine if the heap is empty
    return false;
}

// template <class T, class Compare>
void heap::getElems(std::vector<Node*> & heaped) const
{
    for (size_t i = root(); i < _elems.size(); i++) {
        heaped.push_back(_elems[i]);
    }
}
bool heap::smaller(Node* a, Node* b) {
    return (a->dist < b->dist);
}