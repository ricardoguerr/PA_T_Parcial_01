#include "pch.h"
#include "../PA_T_Parcial_01/Ejercicio02.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <future>

using ::testing::TestWithParam;
using ::testing::ValuesIn;
using ::std::tuple;
using ::std::vector;
using ::std::string;

#define ASSERT_DURATION_LE(secs, stmt) { \
  std::promise<bool> completed; \
  auto stmt_future = completed.get_future(); \
  std::thread([&](std::promise<bool>& completed) { \
    stmt; \
    completed.set_value(true); \
  }, std::ref(completed)).detach(); \
  if(stmt_future.wait_for(std::chrono::seconds(secs)) == std::future_status::timeout) \
    GTEST_FATAL_FAILURE_("       El limite de tiempo se ha excedido (> " #secs \
    " sec.)."); \
}

namespace TestsParcial01 {
	
	class E02Tests : public TestWithParam<tuple<vector<int>, int>> {
	protected:
		Ejercicio02* e02;

		vector<int> houses;
		int expectedResult;

		void SetUp() override {
			e02 = new Ejercicio02();
			std::tie(houses, expectedResult) = GetParam();
		}

		void TearDown() override {
			delete e02;
			e02 = nullptr;
		}

	public:
		static vector<tuple<vector<int>, int>> ReadParams() {
			vector<tuple<vector<int>, int>> params;

			std::ifstream paramsFile("houses.csv");
			string line;

			while (std::getline(paramsFile, line)) {
				std::stringstream strStream(line);
				
				string s;
				std::getline(strStream, s, ',');

				int expectedResult = std::stoi(s);

				vector<int> houses;
				while (std::getline(strStream, s, ',')) {
					houses.push_back(std::stoi(s));
				}

				params.push_back(tuple<vector<int>, int>(houses, expectedResult));
			}

			return params;
		}
	};

	TEST_P(E02Tests, MaxRobbed) {

		ASSERT_DURATION_LE(2, 
			int result = e02->rob(&houses[0], houses.size());
		EXPECT_EQ(expectedResult, result) << "[" << result << "] no  es el resultado esperado. Se esperaba [" << expectedResult << "]";)
	
	}

	INSTANTIATE_TEST_CASE_P(RobandoCasas,
		E02Tests,
		ValuesIn(E02Tests::ReadParams()));
}