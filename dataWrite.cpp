


void dataWrite(string test_type, string test_set, int max, double time)
{
    ofstream outfile;
    outfile.open("data.csv", ios::app);
    outfile << test_type << "," << test_set << "," << max << "," << time;
    outfile << endl;
    outfile.close();
}