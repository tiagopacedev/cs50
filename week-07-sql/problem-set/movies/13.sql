/*
Write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
Your query should output a table with a single column for the name of each person.
There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
Kevin Bacon himself should not be included in the resulting list.
*/

SELECT DISTINCT other_people.name
FROM people AS other_people
JOIN stars AS other_stars ON other_people.id = other_stars.person_id
JOIN movies AS other_movies ON other_stars.movie_id = other_movies.id
JOIN stars AS bacon_stars ON other_movies.id = bacon_stars.movie_id
JOIN people AS bacon ON bacon_stars.person_id = bacon.id
WHERE bacon.name = 'Kevin Bacon'
AND bacon.birth = 1958
AND other_people.name <> 'Kevin Bacon';
