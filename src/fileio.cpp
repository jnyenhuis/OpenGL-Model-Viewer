#include "fileio.h"

#include <fstream>

std::string OpenGlModelViewer::readAllText(std::string filename) {
    // Efficiently read file into a string.
    // https://stackoverflow.com/questions/2912520/read-file-contents-into-a-string-in-c
    std::ifstream ifs(filename);
    std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    return content;
}
