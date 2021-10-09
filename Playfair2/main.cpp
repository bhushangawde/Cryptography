#include <iostream>
#include <string>
using namespace std;

class playfair
{
public:
    void doIt( string k, string t)
    {
    	createGrid( k, true );
    	getTextReady( t, true, true );
        doIt( 1 );
        show_op(1);
        doIt( -1 );
    	show_op(-1);
    }

    void doIt( int dir )
    {
	int a, b, c, d;
	string ntxt;
	for( string::const_iterator ti = tt.begin(); ti != tt.end(); ti++ )
	{
	    if( getCharPos( *ti++, a, b ) )
        {
            if( getCharPos( *ti, c, d ) )
            {
                if( a == c )
                {
                    ntxt += getChar( a, b + dir ); ntxt += getChar( c, d + dir );
                }
                else if( b == d )
                {
                    ntxt += getChar( a + dir, b ); ntxt += getChar( c + dir, d );
                }
                else
                {
                    ntxt += getChar( c, b ); ntxt += getChar( a, d );
                }
            }
        }

	}
	tt = ntxt;
    }

    void show_op(int den)
    {
    if(den==1)
    {
        cout<<"\n\nEncrypted Text:-"<<endl;
    }
    else if(den==-1)
    {
        cout<<"\n\nDecrypted Output:-"<<endl;
    }
	string::iterator si = tt.begin(); int cnt = 0;
	while( si != tt.end() )
	{
	    cout << *si; si++; cout << *si << " ";
	    si++;
	    if( ++cnt >= 26 )
            cout << endl, cnt = 0;
	}
	cout << endl << endl;
    }

    char getChar( int a, int b )
    {
	return m[ (b + 5) % 5 ][ (a + 5) % 5 ];
    }

    bool getCharPos( char l, int &a, int &b )
    {
	for( int y = 0; y < 5; y++ )
	    for( int x = 0; x < 5; x++ )
		if( m[y][x] == l )
		{ a = x; b = y; return true; }

	return false;
    }

    void getTextReady( string t, bool ij, bool e )
    {
    	for( string::iterator si = t.begin(); si != t.end(); si++ )
    	{
    	    *si = toupper( *si );
            if( *si < 65 || *si > 90 ) continue;
    	    if( *si == 'J' && ij ) *si = 'I';
    	    else if( *si == 'Q' && !ij ) continue;
    	    tt += *si;
    	}

    	if( e )
    	{
    	    string ntxt = ""; size_t len = tt.length();
    	    for( size_t x = 0; x < len; x += 2 )
    	    {
    		ntxt += tt[x];
    		if( x + 1 < len )
    		{
    		    if( tt[x] == tt[x + 1] ) ntxt += 'X';
    		    ntxt += tt[x + 1];
    		}
    	    }
    	    tt = ntxt;
    	}
    	if( tt.length() & 1 )
            {
                tt += 'X';
            }
    }

    void createGrid( string k, bool ij )
    {
	if( k.length() < 1 ) k = "KEYWORD";
	k += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string nk = "";
	for( string::iterator si = k.begin(); si != k.end(); si++ )
	{
	    *si = toupper( *si );
	    if( nk.find( *si ) == -1 ) nk += *si;
	}
	copy( nk.begin(), nk.end(), &m[0][0] );
    }
    string tt;
    char m[5][5];
};

int main()
{
    string key, i, txt;
    cout << "Enter a en/decryption key: ";
    getline( cin, key );
    cout << "Enter the text: ";
    getline( cin, txt );
    playfair pf;
    pf.doIt( key, txt);
    return 0;
}
