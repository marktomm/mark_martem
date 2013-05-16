#include <boost/filesystem.hpp>
#include <boost/format.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
using namespace boost;
using namespace boost::filesystem;
using namespace boost::posix_time;

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		cout << format("USAGE: ./filesystem /path/to/dir\n");
		return 1;
	}

	ptime stop, start = microsec_clock::universal_time();
	time_duration t_dur;
	path p(*(argv +1));

	try
	{
		if(exists(p))
		{
			if(is_regular_file(p))
				{
				cout << format("%2%Is not a directory.Type: file\nSize is %1%\n") % file_size(p) % *(argv +1);
				return 1;
				}
			else if(is_directory(p))
			{
				cout << format("List of files int %1%") % *(argv +1);
				typedef vector<path> vec;
				vec v;

				copy(directory_iterator(p), directory_iterator(), back_inserter(v));

				sort(v.begin(), v.end());

				for(vec::const_iterator it (v.begin()); it != v.end(); ++it)
				{
					stop = microsec_clock::universal_time();
					t_dur = stop - start;
					cout << format("Time: %2% file: %1%\n") % it->filename() % t_dur;
				}
			}
			else
			{
				cout << format("%1% exists, but is neither a regular file or directory\n") % p;
				return 1;
			}
		}
		else
		{
			cout << format("%1% does not exist\n") % p;
			return 1;
		}
	}
	catch(const filesystem_error& ex)
	{
		cout << format("%1%\n") % ex.what();
		return 1;
	}

	stop = microsec_clock::universal_time();
	t_dur = stop - start;
	cout << format("Total running time was: %1%\n") % t_dur;

	return 0;
}
