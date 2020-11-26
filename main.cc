#include <iostream>
#include <vector>
#include <filesystem>

struct Tree {
    void traverse(std::string path, int depth) {
        using namespace std::filesystem;

        directory_iterator it(path);

        std::string spaces = std::string(depth*4, ' ');

        for (const directory_entry& e : it) {
            if (is_directory(e)) {
                std::cout << spaces << e.path().filename().string() << std::endl;
                traverse(e.path(), depth+1);
            } else {
                std::cout << spaces << e.path().filename().string() << std::endl;
            }
        }
    }
};

int main() {
    Tree tree{};
    tree.traverse("./", 0);
}
