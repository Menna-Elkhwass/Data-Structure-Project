class Map {
    static class Map* root;
    static int cnt;  // Number of elements in the map
    Map *left, *right, *par;
    int first, second, depth;
};
int size(void);
void insert(int first, int second);
Map* insert(int first);
int& operator[](int key);
Map* iterator(int first);
Map* find(int first);
