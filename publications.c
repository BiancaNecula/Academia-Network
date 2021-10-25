
#include "publications.h"
#include "LinkedList.h"
#include "Hashtable.h"

typedef struct paper {
    char* title;
    int64_t id;
    char* venue;
    int year;
    char** author_names;
    int64_t* author_ids;
    char** institutions;
    int num_authors;
    char** fields;
    int num_fields;
    int64_t* references;
    int num_refs;    
} paper;

typedef struct publications_data {
    struct Hashtable *ht;
} PublData;

PublData* init_publ_data(void) {
    PublData *lib;	
    lib = malloc(sizeof(PublData));
    lib->ht = malloc(sizeof(struct Hashtable));
    init_ht(lib->ht, 100000, hash_function_int, compare_function_ints);
    return lib;
}

void destroy_publ_data(PublData* data) {
    /* TODO: implement destroy_publ_data */
}

void add_paper(PublData* data, const char* title, const char* venue,
    const int year, const char** author_names, const int64_t* author_ids,
    const char** institutions, const int num_authors, const char** fields,
    const int num_fields, const int64_t id, const int64_t* references,
    const int num_refs) {
    paper *art;
    art = malloc(sizeof(paper));
    memcpy(art->title, title, sizeof(char) * (strlen(title)+1));
    memcpy(&art->id, &id, sizeof(int64_t));
    memcpy(art->venue, venue, sizeof(char) * (strlen(venue)+1));
    art->year = year;
    for(int i = 0; i<num_authors; i++)
    	memcpy(art->author_names[i], author_names[i], sizeof(char) * (strlen(author_names[i])+1));
    for(int i = 0; i<num_authors; i++)
    	art->author_ids[i]= author_ids[i];
    for(int i = 0; i<num_authors; i++)
        memcpy(art->institutions[i], institutions[i], sizeof(char) * (strlen(institutions[i])+1));
    art->num_authors = num_authors;
    for(int i = 0; i<num_fields; i++) 
    	memcpy(art->fields[i], fields[i], sizeof(char) * (strlen(fields[i])+1));
    art->num_fields = num_fields;
    for(int i = 0; i<num_refs; i++)
    	art->references[i] = references[i];
    art->num_refs = num_refs;
    put(data->ht, &(art->id), 8, art);

}

char* get_oldest_influence(PublData* data, const int64_t id_paper) {
    /* TODO: implement get_oldest_influence */

    return NULL;
}

float get_venue_impact_factor(PublData* data, const char* venue) {
 /*   int i = 0, j = 0;
    int i2, j2, cnt_ref = 0, cnt_art = 0;
    float avg;
    struct Node *curr, *curr2;
    while(i < data->ht->size){
	if(get_size(&data->ht->buckets[j]) > 0){
	       for(int k =0; k<=get_size(&data->ht->buckets[j]); k++){
	       		curr = data->ht->buckets[i].head;
	 		if(!strcmp(curr->data->venue, venue)){
				i2 = 0; j2 = 0;
				cnt_art++;
				while(i2 < data->ht->size){
					if(data->ht->buckets[j2].size > 0){
						for(int k2 =0; k2<=data->ht->buckets[j2].size; k2++){
							curr2 = data->ht->buckets[j2].head;
							for(int i3 = 0; i3 <=curr2->data->num_refs; i3++){
								if(!strcmp(curr2->data->references[i3], curr->data->id)){
									cnt_ref++;
								}
							}
							i2++;
							curr2 = curr2->next;
						}
						j2++;

					}
				}
			}
			i++;
			curr = curr->next;
		}
	        j++;
	}
   }	
    avg = (float)cnt_ref / cnt_art; */
    return 0.f;
}

int get_number_of_influenced_papers(PublData* data, const int64_t id_paper,
    const int distance) {
    /* TODO: implement get_number_of_influenced_papers */

    return -1;
}

int get_erdos_distance(PublData* data, const int64_t id1, const int64_t id2) {
    /* TODO: implement get_erdos_distance */

    return -1;
}

char** get_most_cited_papers_by_field(PublData* data, const char* field,
    int* num_papers) {
    /* TODO: implement get_most_cited_papers_by_field */

    return NULL;
}

int get_number_of_papers_between_dates(PublData* data, const int early_date,
    const int late_date) {
    /* TODO: implement get_number_of_papers_between_dates */

    return 0;
}

int get_number_of_authors_with_field(PublData* data, const char* institution,
    const char* field) {
    /* TODO: implement get_number_of_authors_with_field */

    return 0;
}

int* get_histogram_of_citations(PublData* data, const int64_t id_author,
    int* num_years) {
    /* TODO: implement get_histogram_of_citations */

    *num_years = 0;

    return NULL;
}

char** get_reading_order(PublData* data, const int64_t id_paper,
    const int distance, int* num_papers) {
    /* TODO: implement get_reading_order */

    *num_papers = 0;

    return NULL;
}

char* find_best_coordinator(PublData* data, const int64_t id_author) {
    /* TODO: implement find_best_coordinator */

    return NULL;
}
