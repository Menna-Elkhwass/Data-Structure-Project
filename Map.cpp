int size(void) {
    return cnt;
}

void insert(int first, int second)
{
    Map* temp = iterator(first);
 
    if (temp == nullptr)    // If element doesnot exist already
        insert(first)->second = second;
     
    else
        temp->second = second;   // If element exists already update it
}

Map* insert(int first)
{
    cnt++;
    Map* newnode = create(first);

    if (root == nullptr) {
        root = newnode;
        return root;
    }
    Map *temp = root, *prev = nullptr;
    while (temp != nullptr) {
        prev = temp;
        if (first < temp->first)
            temp = temp->left;
        else if (first > temp->first)
            temp = temp->right;
        else {
            free(newnode);
            cnt--;
            return temp;
        }
    }
    if (first < prev->first)
        prev->left = newnode;
    else
        prev->right = newnode;
     
    newnode->par = prev;
    balance(newnode);
    return newnode;
}
 
int& operator[](int key) {
    return insert(key)->second;
}

Map* iterator(int first)
{
    Map* temp = root;
    while (temp != nullptr && temp->first != first) {
        if (first < temp->first) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }
    return temp;
}
 
Map* find(int first) {
    return iterator(first);
}
