class Map {
    static class Map* root;
    static int cnt;  // Number of elements in the map
    Map *left, *right, *par;
    int first, second, depth;
};
