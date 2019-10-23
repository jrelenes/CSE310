#define	STATE_LEN	15
#define	MONTH_LEN	10
#define	EVENT_LEN	26
#define	COUNTY_LEN	30
#define	TOR_LEN		4
#define DATE_LEN    20
#define FAT_LOC     25

struct annual_storms{
	int year; // Year of storm events
	struct storm_event **events;  // Pointer to array of storm events for the given year
};

struct storm_event{
	int event_id; // Event id
	char state[ STATE_LEN ]; // State name
	int year; // Four digit year of event
	char month_name[ MONTH_LEN ]; // Month of event
	char event_type[ EVENT_LEN ]; // Event type
	char cz_type; // Where event happened, C, Z, or M
	char cz_name[ COUNTY_LEN ]; // Name of county/zone
	int injuries_direct; // Number of direct injuries
	int injuries_indirect; // Number of indirect injuries
	int deaths_direct; // Number of direct deaths
	int deaths_indirect; // Number of indirect deaths
	int damage_property; // Amount of property damage; convert to integer
	int damage_crops; // Amount of crop damage; convert to integer
	char tor_f_scale[ TOR_LEN ]; // Strength of tornado on Fujita scale
    struct fatality_event **f; // Linked list of fatalities associated with this storm event
};

struct fatality_event{
    int fatality_id; // Identifier of the fatality
    int event_id; // Identifier of the storm event/////////people killed in the same storm have the same event id
    char fatality_type; // D or I
    char fatality_date[ DATE_LEN ]; // Date and time of fatality
    int fatality_age; // Age of fatality
    char fatality_sex; // Gender of fatality
    char fatality_location[ FAT_LOC ]; // Location of fatality
	struct fatality_event *next;
};

struct hash_table_entry{
    int event_id; // Event id -- key used to hash on// this is the key
    int year; // Year of storm event// used to find the location of the main array
    int event_index; // For the given year, the index into array of storm events// used to find the location of second array
	struct hash_table_entry *next;//event data//event address/structure member///the second array already constains all this information
};

//struct storm_event *next;
//struct storm_event *next;

// struct hash_table_entry a;
// a.event_id == a.storm.event_id

// struct hash_table_entry * hashtable[sizeofhashtable]


struct bst{ // A binary search tree
    char *s; // String corresponding to either a state or a month_name
    int event_id; // Identifier of storm event
    struct bst *left;  // Pointer to the left subtree
    struct bst *right;  // Pointer to the right subtree
};

