/*
Write a SQL query that returns the average energy of songs that are by Drake.
Your query should output a table with a single column and a single row containing the average energy.
You should not make any assumptions about what Drake’s artist_id is.
*/

-- Sub Query:
SELECT AVG(energy)
FROM songs
WHERE artist_id = (
    SELECT id
    FROM artists
    WHERE name = "Drake");

-- or:

-- JOIN:
SELECT AVG(energy)
FROM songs
JOIN artists
ON artists.id = songs.artist_id
WHERE name = 'Drake';
