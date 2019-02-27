#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <functional>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'findSchedules' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER workHours
 *  2. INTEGER dayHours
 *  3. STRING pattern
 */

vector<string> findSchedules(int workHours, int dayHours, string pattern) {
	vector<string> _findSchedules;					// temporary variable to store the vector
	vector<string>::iterator it;					// the iterator for the vector
	int openDays = 0;								// the ammount of days open to be filled
	stringstream schedule;							// the string who will store the schedule
	string _schedule;								// the string to alterate the stringstream content

	int pos;										// variable used in later process of ordenation
	int openCount = 0;								// variable used to store open possibles slots to new possibilities
	string patternOpenSymbol = "?";					// standard symbol for openDays in pattern string
	for (int i = 0; i < pattern.length(); i++)
	{
		if (strcmp(pattern.at[i].c_str(), patternOpenSymbol.c_str()))
		{
			openDays++;
		}
		else
		{
			workHours -= (pattern.at[i] - '0');
		}
	}

	pos = openDays;
	it = _findSchedules.begin();

	if ((workHours / openDays) == dayHours)
	{
		for (int i = 0; i < pattern.length(); i++)
		{
			if (strcmp(pattern.at[i].c_str(), patternOpenSymbol.c_str()))
			{
				schedule << dayHours;
			}
			else
			{
				schedule << pattern.at[i];
			}
		}
		it = _findSchedules.insert(it, schedule.str());
		return _findSchedules;
	}
	else
	{
		if (dayHours > workHours)
		{
			for (int i = 0; i < openDays; i++)
			{
				for (int j = 0; j < pattern.length; j++)
				{
					if (strcmp(pattern.at[j].c_str(), patternOpenSymbol.c_str()))
					{
						if ((pos - 1) == openCount)
						{
							schedule << workHours;
						}
						else
						{
							schedule << 0;
						}
						openCount++;
					}
					else
					{
						schedule << pattern.at[j];
					}
				}
				it = _findSchedules.insert(it, schedule.str());
				schedule.str(string());
				openCount = 0;
				pos--;
			}
			return _findSchedules;
		}
		else
		{
			if ((workHours % dayHours) == 0)
			{
				int daysToWork = workHours / dayHours;

				_schedule = "0000000";

				for (int i = openDays - daysToWork; i >= 0; i--)
				{
					_schedule = "0000000";
					_schedule.at[i] = std::to_string(dayHours);
					if (daysToWork > 1)
					{
						for (int j = (openDays - daysToWork) + 1; j > i; j--)
						{
							_schedule = "0000000";
							_schedule.at[i] = std::to_string(dayHours);
							_schedule.at[j] = std::to_string(dayHours);
							if (daysToWork > 2)
							{
								for (int k = (openDays - daysToWork) + 2; k > j; k--)
								{
									_schedule = "0000000";
									_schedule.at[i] = std::to_string(dayHours);
									_schedule.at[j] = std::to_string(dayHours);
									_schedule.at[k] = std::to_string(dayHours);
									if (daysToWork > 3)
									{
										for (int x = (openDays - daysToWork) + 3; x > k; x--)
										{
											_schedule = "0000000";
											_schedule.at[i] = std::to_string(dayHours);
											_schedule.at[j] = std::to_string(dayHours);
											_schedule.at[k] = std::to_string(dayHours);
											_schedule.at[x] = std::to_string(dayHours);
											if (daysToWork > 4)
											{
												for (int y = (openDays - daysToWork) + 4; y > x; y--)
												{
													_schedule = "0000000";
													_schedule.at[i] = std::to_string(dayHours);
													_schedule.at[j] = std::to_string(dayHours);
													_schedule.at[k] = std::to_string(dayHours);
													_schedule.at[x] = std::to_string(dayHours);
													_schedule.at[y] = std::to_string(dayHours);
													if (daysToWork > 5)
													{
														for (int z = (openDays - daysToWork) + 5; z > y; z--)
														{
															_schedule = "0000000";
															_schedule.at[i] = std::to_string(dayHours);
															_schedule.at[j] = std::to_string(dayHours);
															_schedule.at[k] = std::to_string(dayHours);
															_schedule.at[x] = std::to_string(dayHours);
															_schedule.at[y] = std::to_string(dayHours);
															_schedule.at[z] = std::to_string(dayHours);
															it = _findSchedules.insert(it, _schedule);
														}
													}
													if (!(std::find(_findSchedules.begin(), _findSchedules.end(), _schedule) != _findSchedules.end()))
													{
														it = _findSchedules.insert(it, _schedule);
													}
												}
											}
											if (!(std::find(_findSchedules.begin(), _findSchedules.end(), _schedule) != _findSchedules.end()))
											{
												it = _findSchedules.insert(it, _schedule);
											}
										}
									}
									if (!(std::find(_findSchedules.begin(), _findSchedules.end(), _schedule) != _findSchedules.end()))
									{
										it = _findSchedules.insert(it, _schedule);
									}
								}
							}
							if (!(std::find(_findSchedules.begin(), _findSchedules.end(), _schedule) != _findSchedules.end()))
							{
								it = _findSchedules.insert(it, _schedule);
							}
						}
					}
					if (!(std::find(_findSchedules.begin(), _findSchedules.end(), _schedule) != _findSchedules.end()))
					{
						it = _findSchedules.insert(it, _schedule);
					}
				}
				return _findSchedules;
			}
			else
			{
				int lastDayWorkHour = workHours % dayHours;

				if ((workHours / dayHours) == (openDays - 1))
				{
					for (int i = 0; i < openDays; i++)
					{
						for (int j = 0; j < pattern.length(); j++)
						{
							if (strcmp(pattern.at[j].c_str(), patternOpenSymbol.c_str()))
							{
								if ((pos - 1) == openCount)
								{
									schedule << lastDayWorkHour;
								}
								else
								{
									schedule << dayHours;
								}
								openCount++;
							}
							else
							{
								schedule << pattern.at[j];
							}
						}
						it = _findSchedules.insert(it, schedule.str());
						schedule.str(string());
						openCount = 0;
						pos--;
					}
					return _findSchedules;
				}
				else
				{
					schedule.str(string());
					for (int a = 0; a < 7; a++)
					{
						schedule << dayHours;
					}

					int daysToWork = workHours / dayHours + 1;

					for (int i = openDays - daysToWork; i >= 0; i--)
					{
						schedule.str(string());
						for (int a = 0; a < 7; a++)
						{
							schedule << dayHours;
						}
						_schedule.at[i] = std::to_string(lastDayWorkHour);
						if (daysToWork > 1)
						{
							for (int j = (openDays - daysToWork) + 1; j > i; j--)
							{
								schedule.str(string());
								for (int a = 0; a < 7; a++)
								{
									schedule << dayHours;
								}
								_schedule.at[i] = std::to_string(lastDayWorkHour);
								_schedule.at[j] = '0';
								if (daysToWork > 2)
								{
									for (int k = (openDays - daysToWork) + 2; k > j; k--)
									{
										schedule.str(string());
										for (int a = 0; a < 7; a++)
										{
											schedule << dayHours;
										}
										_schedule.at[i] = std::to_string(lastDayWorkHour);
										_schedule.at[j] = '0';
										_schedule.at[k] = '0';
										if (daysToWork > 3)
										{
											for (int x = (openDays - daysToWork) + 3; x > k; x--)
											{
												schedule.str(string());
												for (int a = 0; a < 7; a++)
												{
													schedule << dayHours;
												}
												_schedule.at[i] = std::to_string(lastDayWorkHour);
												_schedule.at[j] = '0';
												_schedule.at[k] = '0';
												_schedule.at[x] = '0';
												if (daysToWork > 4)
												{
													for (int y = (openDays - daysToWork) + 4; y > x; y--)
													{
														schedule.str(string());
														for (int a = 0; a < 7; a++)
														{
															schedule << dayHours;
														}
														_schedule.at[i] = std::to_string(lastDayWorkHour);
														_schedule.at[j] = '0';
														_schedule.at[k] = '0';
														_schedule.at[x] = '0';
														_schedule.at[y] = '0';
														if (daysToWork > 5)
														{
															for (int z = (openDays - daysToWork) + 5; z > y; z--)
															{
																schedule.str(string());
																for (int a = 0; a < 7; a++)
																{
																	schedule << dayHours;
																}
																_schedule.at[i] = std::to_string(lastDayWorkHour);
																_schedule.at[j] = '0';
																_schedule.at[k] = '0';
																_schedule.at[x] = '0';
																_schedule.at[y] = '0';
																_schedule.at[z] = '0';
																it = _findSchedules.insert(it, _schedule);
															}
														}
														if (!(std::find(_findSchedules.begin(), _findSchedules.end(), _schedule) != _findSchedules.end()))
														{
															it = _findSchedules.insert(it, _schedule);
														}
													}
												}
												if (!(std::find(_findSchedules.begin(), _findSchedules.end(), _schedule) != _findSchedules.end()))
												{
													it = _findSchedules.insert(it, _schedule);
												}
											}
										}
										if (!(std::find(_findSchedules.begin(), _findSchedules.end(), _schedule) != _findSchedules.end()))
										{
											it = _findSchedules.insert(it, _schedule);
										}
									}
								}
								if (!(std::find(_findSchedules.begin(), _findSchedules.end(), _schedule) != _findSchedules.end()))
								{
									it = _findSchedules.insert(it, _schedule);
								}
							}
						}
						if (!(std::find(_findSchedules.begin(), _findSchedules.end(), _schedule) != _findSchedules.end()))
						{
							it = _findSchedules.insert(it, _schedule);
						}
					}
					return _findSchedules;
				}
			}
		}
	}
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string workHours_temp;
	getline(cin, workHours_temp);

	int workHours = stoi(ltrim(rtrim(workHours_temp)));

	string dayHours_temp;
	getline(cin, dayHours_temp);

	int dayHours = stoi(ltrim(rtrim(dayHours_temp)));

	string pattern;
	getline(cin, pattern);

	vector<string> result = findSchedules(workHours, dayHours, pattern);

	for (int i = 0; i < result.size(); i++) {
		fout << result[i];

		if (i != result.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";

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
