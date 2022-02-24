#include <bits/stdc++.h>
using namespace std;

class VanEmdeBose {
		public:
			int universe_size;
			int minimum;
			int maximum;
			VanEmdeBose* summary;
			vector<VanEmdeBose*> clusters;

			int cluster_no(int x){                                     // Function to return cluster numbers in which key is present
				int div = ceil(sqrt(universe_size));
				return x / div;
			}

			int position(int x){                                       // Function to return position of x in cluster 
				int mod = ceil(sqrt(universe_size));
				return x % mod;
			}

			int generate_index(int x, int y){                           // Function to return the index from cluster number and position
				int ru = ceil(sqrt(universe_size));
				return x * ru + y;
			}

			VanEmdeBose(int size){
				universe_size = size;
				minimum = -1;
				maximum = -1;

				// Base case
				if (size <= 2) {
					summary = nullptr;
					clusters = vector<VanEmdeBose*>(0, nullptr);
				}
				else {
					int no_clusters = ceil(sqrt(size));                           //total cluster to in the universe
					summary = new VanEmdeBose(no_clusters);                       // Assigning VEB(sqrt(u)) to summary

					clusters = vector<VanEmdeBose*>(no_clusters, nullptr);        // Creating array of VEB Tree pointers of size sqrt(u)

					for (int i = 0; i < no_clusters; i++) {                       // Assigning VEB(sqrt(u)) to all its clusters
						clusters[i] = new VanEmdeBose(ceil(sqrt(size)));
					}
				}
			}
		};



int VEB_minimum(VanEmdeBose* set){                                                // Function to return the minimum value from the tree if it exists
		return set->minimum;
	}

int VEB_maximum(VanEmdeBose* set){                                                // Function to return the maximum value from the tree if it exists
		return set->maximum;
	}

void insert(VanEmdeBose* set, int key){                                           // Function to insert a key in the tree
		if (set->minimum == -1) {                                                 // If no key is present in the tree then set both minimum and maximum to the key 
			set->minimum = key;
			set->maximum = key;				
		}
		else {
			if (key < set->minimum)                                               // If the key is less than the current minimum then swap it with the current minimum because this minimum is actually minimum of one of the internal cluster so as we go deeper into the Van Emde Boas we need to take that minimum to its real position
				swap(set->minimum, key);
			

			if (set->universe_size > 2) {                                         // Not base case then...
				if (VEB_minimum(set->clusters[set->cluster_no(key)]) == -1) {     // If no key is present in the cluster then insert key into both cluster and summary
					insert(set->summary, set->cluster_no(key));

					// Sets the minimum and maximum of cluster to the key as no other keys are present we will stop at this level
					set->clusters[set->cluster_no(key)]->minimum = set->position(key);
					set->clusters[set->cluster_no(key)]->maximum = set->position(key);
				}
				else                                                               // If there are other elements in the tree then recursively go deeper into the structure to set attributes accordingly
					insert(set->clusters[set->cluster_no(key)], set->position(key));
		
			}

			if (key > set->maximum)                                                 // Sets the key as maximum it is greater than current maximum
				set->maximum = key;
		}
	}


int VEB_successor(VanEmdeBose* set, int key){                                      // Function to find the successor of the given key
		if (set->universe_size == 2) {                                             // Base case: If key is 0 and its successor is present then return 1 else return null
			if (key == 0 && set->maximum == 1) 
				return 1;
			else 
				return -1;
		}
		else if (set->minimum != -1 && key < set->minimum)                          // If key is less then minimum then return minimum because it will be successor of the key
			return set->minimum;

		else {
			int max_incluster = VEB_maximum(set->clusters[set->cluster_no(key)]);   // Find successor inside the cluster of the key First find the maximum in the cluster
			int offset=0, succ_cluster=0;

			if (max_incluster != -1 && set->position(key) < max_incluster) {        // If there is any key( maximum!=-1 ) present in the cluster then find the successor inside of the cluster
				offset = VEB_successor(set->clusters[set->cluster_no(key)],set->position(key));
				return set->generate_index(set->cluster_no(key), offset);
			}

			else {                                                                  // Otherwise look for the next cluster with at least one key present
				succ_cluster = VEB_successor(set->summary, set->cluster_no(key));   // If there is no cluster with any key present in summary then return null
				if (succ_cluster == -1)
					return -1;

				else {                                                               // Find minimum in successor cluster which will be the successor of the ke
					offset = VEB_minimum(set->clusters[succ_cluster]);
					return set->generate_index(succ_cluster, offset);
				}
			}
		}
	}

int main(){

	VanEmdeBose* set = new VanEmdeBose(64); 
    cout<<"Enter the no random input : ";
    int n;cin>>n;
	for(int i=0;i<n;i++){
		int x=rand()%64;
		cout<<x<<" ";
		insert(set,x);
	}
	cout<<"\n";
	cout<<"Enter the no who's successor you want to find : ";
	int num;cin>>num;
	cout<<VEB_successor(set,num);

	return 0;
}
