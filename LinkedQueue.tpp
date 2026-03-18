// Run bash: bash generate_main.sh
// compilation: g++ -std=c++11 main.cpp -o main

template <typename T>
LinkedQueue<T>::LinkedQueue() {
    // TODO
    head = nullptr;
    last = nullptr;
    this->length = 0;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    head = nullptr; // before copying, your queue should initialize head & last to nullptr and length to zero so copy() builds it cleanly. 
    last = nullptr; // functions like enqueue() and dequeue() depennd on head and last to be initialized so that they dont contain garbage values from the beginning
    this->length = 0; // when copy(copyObj) runs, it calls the enqueue(), the enqueue() executes the isEmpty(), and isEmpty uses this->length to check if length is zero or not, so if length, head, and last or not initialized then they will have garbage values which could affect program
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    // TODO
    if (isEmpty()) {
        throw string("back: error, queue is empty, cannot access the back");
    }
    return last->value;
}

template <typename T>
void LinkedQueue<T>::clear() {
    // TODO
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    // TODO
    Node* temp = copyObj.head;

    while (temp != nullptr) {
        enqueue(temp->value);
        temp = temp->next;
    }
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    // TODO
    if (isEmpty()) {
        throw string("Cannot dequeue from an empty queue");
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    this->length--;

    if (head == nullptr) {
        last = nullptr;
    }
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    // TODO
    Node* newNode = new Node(elem);

    if (isEmpty()) {
        head = newNode;
        last = newNode;
    }
    else {
        last->next = newNode;
        last = newNode;
    }

    this->length++;
}

template <typename T>
T LinkedQueue<T>::front() const {
    // TODO
    if (isEmpty()) {
        throw string("front: error, queue is empty, cannot access the front");
    }
    return head->value;
}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}
