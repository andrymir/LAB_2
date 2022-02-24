#include "csvreader.h"

CSVReader::CSVReader(const std::string& filename)
{
 fin.open(filename);
}
CSVReader::~CSVReader(){
    fin.close();
}
std::vector<std::string> CSVReader::split(const std::string& str, char delim)
{
    std::vector<std::string> tokens;

    if (!str.empty())
    {
        size_t start = 0, end;
        do {
            end = str.find(delim, start);
            tokens.push_back(str.substr(start, (end - start)));

            start = end + 1;
        } while (end != std::string::npos);
    }

    return tokens;
}

std::vector<Cars> CSVReader::readAll(){
    std::vector<Cars> result;

            if(fin.is_open())
            {
                std::string line;


                while (getline(fin,line))
                   {
                    auto v = split(line, ';');

                    Cars car;
                    car.n=std::stoi(v[0]);
                    car.model = v[1];
                    car.color=static_cast<Color>(std::stoi(v[2]));
                    car.year=std::stoi(v[3]);

                    result.push_back(car);
                   }
            }
            sort(result.begin(),result.end(),[](const Cars &c1, const Cars &c2){
                return c1.n<c2.n;});
            return result;
}
