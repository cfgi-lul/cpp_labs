using namespace std;

template<class T>
struct Node {
    T val;
    Node *next;
};

template<class T>
Node<T> *first(T d);

template<class T>
void add(Node<T> **pend, T d);

template<class T>
Node<T> *find(Node<T> *const pbeg, T i);

template<class T>
int remove(Node<T> **pbeg, Node<T> **pend, T key);

template<class T>
Node<T> *insert(Node<T> *const pbeg, Node<T> **pend, T key, T d);

template<class T>
Node<T> *first(T d) {
    Node<T> *pv = new Node<T>;
    pv->val = d;
    pv->next = 0;
    return pv;
}

template<class T>
void add(Node<T> **pend, T d) {
    Node<T> *pv = new Node<T>;
    pv->val = d;
    pv->next = 0;
    (*pend)->next = pv;
    *pend = pv;
}

template<class T>
Node<T> *find(Node<T> *const pbeg, T d) {
    Node<T> *pv = pbeg;
    while (pv) {
        if (pv->val == d) {
            break;
        }
        pv = pv->next;
    }
    return pv;
}

template<class T>
int remove(Node<T> **pbeg, Node<T> **pend, T key) {
    Node<T> *pkey = find(*pbeg, key);
    if (pkey) {
        if (pkey == *pbeg) {
            *pbeg = (*pbeg)->next;
        } else {
            if (pkey == *pend) {
                (*pend)->next = 0;
            }
        }

        delete pkey;
        return 1;
    }
    return 0;
}

template<class T>
Node<T> *insert(Node<T> *const pbeg, Node<T> **pend, T key, T d) {
    Node<T> *pkey = find(pbeg, key);
    if (pkey) {
        Node<T> *pv = new Node<T>;
        pv->val = d;

        pv->next = pkey->next;
        pkey->next = pv;

        if (pkey != *pend) {

        } else {
            *pend = pv;
        }
        return pv;
    }

    return 0;
}
