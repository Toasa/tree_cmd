#include <iostream>
#include <vector>
#include <filesystem>

void getFileNames(std::string folderPath, std::vector<std::string> &file_names) {
    using namespace std::filesystem;

    directory_iterator it(folderPath);
    for (const directory_entry& e : it)  {
        file_names.push_back(e.path());
    }
}

int main() {
    std::vector<std::string> file_names{};
    getFileNames("./", file_names);
    for_each(
            file_names.begin(),
            file_names.end(),
            [](auto s) { std::cout << s << std::endl; });
}
