Data Structures Course \
HOMEWORK 3 - Academia Network

April, 2020

Bianca Necula \
Faculty of Automatic Control and Computer Science \
315CA 

# Info
```bash
git clone https://github.com/BiancaNecula/Academia-Network.git
```
Run ./check.sh for testing with the checker.   
More info: https://ocw.cs.pub.ro/courses/sd-ca/teme/tema3-2020

# About the project:
A system will be implemented that aggregates information about scientific articles and responds to queries using the latest saved data. During the execution of the program, updates and interspersed queries will be received.  

The topic will be based on scientific articles published at various conferences. Such an article has the following properties:

* Title
* Unique ID
* Year of publication
* Conference at which it was published (single string)
* Fields of study
  * a list of strings. ex: {“Computer Vision”, “Machine Learning”}
  * represent the areas that the current article is studying
* List of authors
 * The following information is received for each author in the list
   * Author name
   * Author ID
   * Associated institution
* List of cited articles (references)
  * At the end of a scientific article are the sources on which it was based to support hypotheses and from which ideas were used. We can say that the current article "is influenced" or "depends on" all the articles in the list of references.
  * This list of cited articles contains the ids of other scientific articles which in turn are entities of the type described in this paragraph and in turn will cite other articles.
  
# About the code:
```C
  PublData* init_publ_data(void) // Dynamic allocation of the structure
  void destroy_publ_data(PublData* data) // Dynamic deallocation of the structure
  void add_paper(PublData* data, const char* title,
    const char* venue, const int year, const char** author_names,
    const int64_t* author_ids, const char** institutions,
    const int num_authors, const char** fields, const int num_fields,
    const int64_t id, const int64_t* references, const int num_refs); // adds this article to the article logic retained in the PublData structure
  char* get_oldest_influence(PublData* data, const int64_t paper); // finding the oldest (with the smallest year of publication) article on which it "depends"
  float get_venue_impact_factor(PublData* data, const char* venue); // average number of citations of all articles published in the journal by the time the query is received
  int get_number_of_influenced_papers(PublData* data, const int64_t id_paper, const int distance); // the total number of articles that were influenced by the given article
  int get_erdos_distance(PublData* data, const int64_t id1, const int64_t id2); // calculating the Erdos distance between the two
  char** get_most_cited_papers_by_field(PublData* data, const char* field, const int* num_papers); // return the titles of the most cited num_papers studying that field
  int get_number_of_papers_between_dates(PublData* data, const int early_date, const int late_date); // will return how many articles were published in total between the two years received as a parameter
  int get_number_of_authors_with_field(PublData* data, const char* institution, const char* field); // the total number of authors who published articles on that field while being associated with the given institution
  int* get_histogram_of_citations(PublData* data const int64_t id_author, int* num_years); // calculating the number of citations of all articles published by the author received as a parameter and making the histogram
  char** get_reading_order(PublData* data, const int64_t id_paper, const int distance, int* num_papers); // return an order in which these articles are read in such a way that the criteria are met
  char* find_best_coordinator(PublData* data, int64_t id_author); // return the name of the author who maximizes the score
  
```

* .Json file parser - Parson  
In order to be able to parse a .json file, as are the files containing the items to be operated, the Parson parser is used.  
The main structure is JSON_Object. It can contain fields (strings, numbers, etc.), arrays (JSON_Arrays), and other JSON_Objects.  
```C
 json_array_get_<data_type>(JSON_Array* array, const char* key) 
 json_object_get_<data_type>(JSON_Object* object, const char* key) 
```
