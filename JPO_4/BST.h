#include <iostream>

template<class T> class Tree;

// ======================================================================
//                    Template Class Node
// ======================================================================

template <class T>
class Node {
public:
   T value;
   Node <T>* leftPtr;
   Node <T>* rightPtr;

   Node(T value);

   Node <T>* left();
   Node <T>* right();
   Node <T>* left(Node <T>* newPtr);
   Node <T>* right(Node <T>* newPtr);

   friend class Tree <T>;
};

// ======================================================================
//                    Template Class Tree
// ======================================================================

template <class T>
class Tree {
protected:
   Node<T>* root;
public:
   Tree();
   virtual ~Tree() {}

   bool isEmpty();
   void insert(T);
   bool contains(T);
   void clear(Node<T>* ptr);
   void inorder(Node<T>*);

   Node<T>* getRoot();
};


// ======================================================================
//                    Template Class Node
// ======================================================================

template<class T>
Node<T>::Node(T value) {
   this->leftPtr = nullptr;
   this->rightPtr = nullptr;
   this->value = value;
}

template<class T>
Node<T>* Node<T>::left() {
   return leftPtr;
}

template<class T>
Node<T>* Node<T>::right() {
   return rightPtr;
}

template<class T>
Node<T>* Node <T>::left(Node <T>* newPtr) {
   leftPtr = newPtr;
   return leftPtr;
}

template <class T>
Node<T>* Node<T>::right(Node <T>* newPtr) {
   rightPtr = newPtr;
   return rightPtr;
}

// ======================================================================
//                    Template Class Tree
// ======================================================================

template<class T>
Tree<T>::Tree() {
   this->root = nullptr;
}

template<class T>
inline bool Tree<T>::isEmpty() {
   if (root == nullptr) {
      return true;
   }
   return false;
}

template<class T>
void Tree<T>::insert(T value) {
   if (root == nullptr) {
      root = new Node<T>(value);
      return;
   }

   Node<T>* current = root;
   Node<T>* child;

   while (current) {
      if (value >= current->value) {
         child = current->left();
         if (child == nullptr) {
            current->left(new Node <T>(value));
            return;
         }
      }
      else {
         child = current->right();
         if (child == nullptr) {
            current->right(new Node <T>(value));
            return;
         }
      }
      current = child;
   }
}

template<class T>
bool Tree<T>::contains(T value) {
   Node <T>* current = root;
   while (current != nullptr) {
      if (current->value == value) return true;
      if (value >= current->value) {
         current = current->left();
      }
      else {
         current = current->right();
      }
   }

   return false;
}

template<class T>
void Tree<T>::clear(Node<T>* ptr) {
   /*if (ptr == nullptr) {
      std::cout << "Tree is clear \n";
      return;
   }*/
   clear(ptr->leftPtr);
   clear(ptr->rightPtr);

   std::cout << "Deleting node: " << ptr->value << std::endl;
   delete ptr;
}

template<class T>
void Tree<T>::inorder(Node<T>* ptr) {
   if (ptr == nullptr)
      return;

   /* first recur on left child */
   inorder(ptr->left());

   /* then print the data of node */
   std::cout << ptr->value << " ";

   /* now recur on right child */
   inorder(ptr->right());
}

template<class T>
inline Node<T>* Tree<T>::getRoot() {
   return root;
}
