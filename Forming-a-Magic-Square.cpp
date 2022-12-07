#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */



int formingMagicSquare(vector<vector<int>> s)
{
	vector<vector<int>> magic0 = { {8,1,6}, {3,5,7}, {4,9,2} };
	vector<vector<int>> magic1 = { {6,1,8}, {7,5,3}, {2,9,4} };
	vector<vector<int>> magic2 = { {4,9,2}, {3,5,7}, {8,1,6} };
	vector<vector<int>> magic3 = { {2,9,4}, {7,5,3}, {6,1,8} };
	vector<vector<int>> magic4 = { {8,3,4}, {1,5,9}, {6,7,2} };
	vector<vector<int>> magic5 = { {4,3,8}, {9,5,1}, {2,7,6} };
	vector<vector<int>> magic6 = { {6,7,2}, {1,5,9}, {8,3,4} };
	vector<vector<int>> magic7 = { {2,7,6}, {9,5,1}, {4,3,8} };

	vector<int> cost(8);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cost[0] += std::abs(s[i][j] - magic0[i][j]);
			cost[1] += std::abs(s[i][j] - magic1[i][j]);
			cost[2] += std::abs(s[i][j] - magic2[i][j]);
			cost[3] += std::abs(s[i][j] - magic3[i][j]);
			cost[4] += std::abs(s[i][j] - magic4[i][j]);
			cost[5] += std::abs(s[i][j] - magic5[i][j]);
			cost[6] += std::abs(s[i][j] - magic6[i][j]);
			cost[7] += std::abs(s[i][j] - magic7[i][j]);
		}
	}

	int min = cost[0];

	for (size_t i = 1; i < cost.size(); ++i)
	{
		if (min > cost[i])
		{
			min = cost[i];
		}
	}

	return min;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);

    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        string s_row_temp_temp;
        getline(cin, s_row_temp_temp);

        vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int s_row_item = stoi(s_row_temp[j]);

            s[i][j] = s_row_item;
        }
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
