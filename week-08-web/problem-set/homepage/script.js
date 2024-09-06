// Your array of posts
const posts = [
    {
        date: "2024-04-07",
        title: "The Power of Static Typing in Programming",
        url:"/post",
        content: "Static typing can prevent many common errors in programming, making your code more reliable and easier to maintain. By catching type errors at compile time, you can avoid many runtime issues."
    },
    {
        date: "2024-04-14",
        title: "Understanding Closures in JavaScript",
        url:"/post",
        content: "Closures are a powerful feature in JavaScript that allow functions to retain access to variables from their outer scope, even after the outer function has returned."
    },
    {
        date: "2024-04-21",
        title: "The Importance of Clean Code",
        url:"/post",
        content: "Writing clean, readable code is essential for maintaining and scaling applications. It not only makes your code easier to understand but also simplifies debugging and future development."
    },
    {
        date: "2024-04-28",
        title: "Asynchronous Programming with Promises",
        url:"/post",
        content: "Promises in JavaScript provide a way to handle asynchronous operations, making your code more readable and manageable. They help avoid callback hell and allow for cleaner error handling."
    },
    {
        date: "2024-05-05",
        title: "Introduction to React Hooks",
        url:"/post",
        content: "React Hooks allow you to use state and other React features in functional components, making your code more concise and easier to understand."
    },
    {
        date: "2024-05-12",
        title: "Exploring CSS Grid Layout",
        url:"/post",
        content: "CSS Grid Layout is a powerful tool for creating complex, responsive web layouts with ease. It allows you to design web pages without the need for floats or positioning."
    },
    {
        date: "2024-05-19",
        title: "Node.js and Express: Building a RESTful API",
        url:"/post",
        content: "Node.js, combined with Express, provides a robust platform for building RESTful APIs. It’s fast, scalable, and suitable for both small and large applications."
    },
    {
        date: "2024-05-26",
        title: "Understanding the Document Object Model (DOM)",
        url:"/post",
        content: "The DOM is a programming interface for HTML and XML documents. It represents the page so that programs can change the document structure, style, and content."
    },
    {
        date: "2024-06-02",
        title: "Version Control with Git and GitHub",
        url:"/post",
        content: "Git and GitHub are essential tools for modern software development. They allow developers to track changes, collaborate, and manage their codebase effectively."
    },
    {
        date: "2024-06-09",
        title: "Responsive Web Design: Best Practices",
        url:"/post",
        content: "Responsive web design ensures that your website looks and functions well on all devices. This approach involves using flexible layouts, images, and CSS media queries."
    }
];


// Function to render posts
function renderPosts() {
    const postsContainer = document.getElementById('posts-container');

    posts.map(post => {
        // Create a div for each post
        const postDiv = document.createElement('div');
        postDiv.className = 'post';

        // Create and append the date element
        const dateElement = document.createElement('p');
        dateElement.textContent = post.date;
        postDiv.appendChild(dateElement);

        // Create and append the title element
        const titleElement = document.createElement('a');
        titleElement.href = post.url;
        titleElement.textContent = post.title;
        titleElement.className = 'post-title';
        postDiv.appendChild(titleElement);

        // Append the post to the container
        postsContainer.appendChild(postDiv);
    });
}

// Call the function to render posts on page load
document.addEventListener('DOMContentLoaded', renderPosts);


document.addEventListener('DOMContentLoaded', function() {
    // Example data - replace with real data from an API or server
    const post = {
        title: "The Power of Static Typing in Programming",
        date: "2024-04-07",
        content: "Static typing can prevent many common errors in programming, making your code more reliable and easier to maintain. By catching type errors at compile time, you can avoid many runtime issues."
    };

    // Set content
    document.getElementById('post-title').textContent = post.title;
    document.getElementById('post-date').textContent = post.date;
    document.getElementById('post-content').innerHTML = `<p>${post.content}</p>`;
});
