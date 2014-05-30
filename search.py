# If on Python 2.X
from __future__ import print_function
import pysolr

# Setup a Solr instance. The timeout is optional.
solr = pysolr.Solr('http://localhost:8983/solr/', timeout=10)

# How you'd index data.
'''
solr.add([
    {
        "id": "C:",
        "title": "anupam",
        "category": "0\C:"
        
    },
    {
        "id": "C:\a",
        "title": "anupam",
        "category": "0\C: 1\C:\a"
        
    },
    {
        "id": "C:\a\b",
        "title": "anupam",
        "category": "0\C: 1\C:\a 2\C:\a\b"
        
    },
    {
        "id": "D:\b",
        "title": "anupam",
        "category": "0\D: 1\D:\b"
        
    },
    {
        "id": "D:\b\d",
        "title": "satish",
        "category": "0\D: 1\D:\b 2\D:\b\d"
        
    }
])
'''

# You can optimize the index when it gets fragmented, for better speed
# and to perform hard commit
#solr.optimize()

# Later, searching is easy. In the simple case, just a plain Lucene-style
# query is fine.
#results = solr.search('satish')

#Indexing data into solr
docs = []
doc = {}
string1 = ""
string2 = ""
for x in range(1,61):
    string1 = "anupam" + str(x) 
    string2 = "satish" + str(x)
    doc = {"id": "C:", "title": string1, "category": "0\C:"}
    docs.append(doc)
    doc = {"id": "C:\d" + str(x), "title": string1, "category": "0\C:\d" + str(x)}
    docs.append(doc)
    doc = {"id": "D:\d"+ str(x) + "\\d" + str(x+1), "title": string1, "category": "0\D:\d" + str(x)+ "\\d" + str(x+1)}
    docs.append(doc)
    doc = {"id": "D:\e" + str(x), "title": string2, "category": "0\D: 1\D:\e" + str(x)}
    docs.append(doc)
    doc = {"id": "D:\e"+ str(x) + "\\e" + str(x+1), "title": string2, "category": "0\D: 1\D:\e"+str(x) + " " + "2\D:\e" + str(x) + "\\e" + str(x+1)}
    docs.append(doc)
    
solr.add(docs)
#print (len(docs))
    
params = {
  'facet': 'on',
  'facet.field': 'category',
  'facet.prefix': '0',
  'rows': '100',
}
results = solr.search('anupam*', **params)

#print(results.facets['facet_fields']['category'])
print(results.facets['facet_fields'])
print("Saw {0} result(s).".format(len(results)))
# Just loop over it to access the results.
for result in results:
    print("The file is '{0}'.".format(result['category']))

# Finally, you can delete either individual documents...
#solr.delete(id='doc_1')

# ...or all documents.
#solr.delete(q='*:*')

