#include "pch.h"
#include "../PA_T_Parcial_01/Ejercicio01.h"
#include <vector>
#include <string>
#include <fstream>

using ::testing::TestWithParam;
using ::testing::ValuesIn;
using ::std::tuple;
using ::std::vector;
using ::std::string;

namespace TestsParcial01 {

	class Ejercicio01Tests : public TestWithParam<string> {
	protected:
		Ejercicio01* e01;

		string phrase;

		void SetUp() override {
			e01 = new Ejercicio01();
			phrase = GetParam();
		}

		void TearDown() override {
			delete e01;
			e01 = nullptr;
		}

		static vector<string> ReadParams(const string& path) {
			vector<string> params;

			std::ifstream paramsFile(path);
			string line;

			while (std::getline(paramsFile, line)) {
				params.push_back(line);
			}

			return params;
		}
	};

	class E01PalindromesTests : public Ejercicio01Tests {
	public:
		static vector<string> GetValidPalindromes() {
			return ReadParams("palindromes.txt");
		}
	};

	class E01NonPalindromesTests : public Ejercicio01Tests {
	public:
		static vector<string> GetNonPalindromes() {
			return ReadParams("non_palindromes.txt");
		}
	};

	TEST_P(E01PalindromesTests, PalindromosValidos) {
		EXPECT_TRUE(e01->isPalindrome(phrase.c_str(), phrase.length())) << phrase << " es un palindromo";
	}

	TEST_P(E01NonPalindromesTests, NoPalindromos) {
		EXPECT_FALSE(e01->isPalindrome(phrase.c_str(), phrase.length())) << phrase << " NO es un palindromo";
	}

	INSTANTIATE_TEST_CASE_P(Palindromos,
		E01PalindromesTests,
		ValuesIn(E01PalindromesTests::GetValidPalindromes()));

	INSTANTIATE_TEST_CASE_P(NoPalindromos,
		E01NonPalindromesTests,
		ValuesIn(E01NonPalindromesTests::GetNonPalindromes()));

}